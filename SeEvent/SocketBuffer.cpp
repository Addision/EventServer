#include "SocketBuffer.h"

void SocketBuffer::Init()
{
	m_oBuffer.first = m_oBuffer.last = m_oBuffer.datap = nullptr;
	m_oBuffer.total_len = 0;
	m_oBuffer.chain_num = 0;
}

void SocketBuffer::Write(const char* data, int size)
{
	BufferChain* chain = GetWriteChain(size);
	if (m_oBuffer.datap == nullptr) m_oBuffer.datap = chain;

	memcpy(chain->buffer + chain->write_pos, data, size);
	chain->write_pos += size;
	m_oBuffer.total_len += size;  // data len
}

void SocketBuffer::Read(char* buf, int size)
{
	if (size > m_oBuffer.total_len) size = m_oBuffer.total_len;
	if (size == 0) return;

	int read_len = 0;
	int can_read_len = 0;
	BufferChain* chain = m_oBuffer.datap;
	while (size > 0 && chain)
	{
		can_read_len = chain->write_pos - chain->read_pos;
		if (can_read_len >= size) can_read_len = size;
		memcpy(buf + read_len, chain->buffer + chain->read_pos, can_read_len);
		m_oBuffer.total_len -= can_read_len;
		read_len += can_read_len;
		size -= can_read_len;
		chain->read_pos += can_read_len;
		if (chain->read_pos == chain->write_pos)
		{
			chain->read_pos = chain->write_pos = 0;
			chain = chain->next;
			m_oBuffer.datap = chain;
		}
	}
}

void SocketBuffer::ReadProtoHead(char* buf, int size)
{
	if (m_oBuffer.total_len <= size) return;  // ������֤��������Э��

	int read_len = 0;
	int can_read_len = 0;
	BufferChain* chain = m_oBuffer.datap;
	while (size > 0 && chain)
	{
		can_read_len = chain->write_pos - chain->read_pos;
		if (can_read_len >= size) can_read_len = size;
		memcpy(buf + read_len, chain->buffer + chain->read_pos, can_read_len);
		read_len += can_read_len;
		size -= can_read_len;
		int pos = chain->read_pos + can_read_len;
		if (pos == chain->write_pos) chain = chain->next;
	}
}

void SocketBuffer::Clear()
{
	struct BufferChain* first = m_oBuffer.first;
	while (first != nullptr)
	{
		delete[] first->buffer;
		struct BufferChain* next = first->next;
		delete first;
		first = next;
	}
	m_oBuffer.first = m_oBuffer.last = m_oBuffer.datap = nullptr;
}

BufferChain* SocketBuffer::NewChain(int size)
{
	BufferChain* chain = new BufferChain;
	Assert(chain);
	chain->buffer = new char[size];
	Assert(chain->buffer);
	memset(chain->buffer, 0, size);
	chain->read_pos = chain->write_pos = 0;
	chain->buffer_len = size;
	chain->next = chain->prev = nullptr;
	InsertNewChain(chain);
	return chain;
}

char* SocketBuffer::PullUp()  // ���������ݷŵ���һ�����в�����ͷָ��
{
	return nullptr;
}

BufferChain* SocketBuffer::GetWriteChain(int size)
{
	// д��ԭ��
	// 1��Ӧ�ô����һ���Ƿ��п��пռ�д������
	// 2������ǰ���Ѿ�����һ����С��Ϊ���ʵĿ�����д��
	// 3������յ�����ĳ��ȴ��ڣ��ܹ�д��size�Ĵ�С����2��������д��һ��������
	if (m_oBuffer.last && m_oBuffer.last->Left() >= size)
	{
		return m_oBuffer.last;
	}
	BufferChain* chain = m_oBuffer.first;
	BufferChain* wait = nullptr;
	while (chain && chain->IsEmpty())
	{
		if (chain->buffer_len >= size)
		{
			if (wait == nullptr) wait = chain;
			else if (wait->buffer_len > chain->buffer_len) wait = chain;
		}
		chain = chain->next;
	}
	int alloc_size = GetAllocSize(size);
	if (wait && wait->buffer_len <= (alloc_size << 1))
	{
		if (m_oBuffer.chain_num > 1)
		{// ��Ҫ���������λ�õ����
			AjustChain(wait);
			return wait;
		}
		return wait;
	}
	return NewChain(alloc_size);
}

int SocketBuffer::TotalLen()
{
	return m_oBuffer.total_len;
}
int SocketBuffer::GetAllocSize(int size)
{
	int alloc_size = 0;
	alloc_size = MIN_BUFFER_SIZE;
	while (alloc_size < size) alloc_size <<= 1;
	Assert(alloc_size < MAX_BUFFER_SIZE);
	return alloc_size;
}

void SocketBuffer::InsertNewChain(BufferChain* chain)
{
	if (m_oBuffer.chain_num == 0)
	{
		m_oBuffer.first = chain;
		m_oBuffer.last = chain;
	}
	else
	{
		m_oBuffer.last->next = chain;
		chain->prev = m_oBuffer.last;
		m_oBuffer.last = chain;
	}
	++m_oBuffer.chain_num;
}

void SocketBuffer::AjustChain(BufferChain* chain)
{
	if (chain->prev)
	{
		chain->prev->next = chain->next;
		chain->next->prev = chain->prev;
	}
	else
	{
		m_oBuffer.first = chain->next;
		chain->next->prev = m_oBuffer.first;
	}
	m_oBuffer.last->next = chain;
	chain->prev = m_oBuffer.last;
	m_oBuffer.last = chain;
	m_oBuffer.last->next = nullptr;
}
