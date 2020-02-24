#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "ThreadBase.h"
#include "Conn.h"
#include <deque>

class ConnThread;
class LoginPlayer;
class Packet;
// ͨ���̳߳ش���sql����
// ��ҵ����������ߺ󱣴浽�ڴ��У�ÿ�����ÿ��5���Ӵ浵һ�μ��ɣ�������߽��������ݱ��浽���ݿ�
class ConnectionPool
{
public:
	ConnectionPool();
	ConnectionPool(int thrdnum);
	~ConnectionPool();
	void Init();
	ConnThread* Malloc();  // ��ȡ�̶߳���
	void Free(ConnThread* conn); // ����һ���̶߳���
	void Stop();
	ConnThread* GetConnThread(std::thread::id& tid);
private:
	int m_conn_num;   //conn thread num
	std::vector<ConnThread*> m_conn_threads;
};

///////////////////////////////// MsgCache /////////////////

class MsgCache
{
public:
	LoginPlayer* m_player;
	Packet* m_packet;
	std::string m_sql;
	result_t m_result;
};

//////////////////////////// ConnThread ///////////////////////

class ConnThread : public ThreadBase
{
	using reqquery_t = std::map<uint64_t, std::string>;
	using reqresult_t = std::map<uint64_t, MariaCpp::ResultSet*>;
	using reqmsgcache_t = std::deque<MsgCache>;
public:
	bool Init();
	void ThreadLoop();
	void AddReqMsg(MsgCache& msgcache);
	MsgCache* GetMsgCache() { return &m_reqmsgcache.front(); }
	bool IsFree() { return m_reqmsgcache.empty(); }
	int GetReqSize() { return m_reqmsgcache.size(); }
private:
	bool Query(MsgCache& msgcache);
private:
	Conn m_conn;
	reqmsgcache_t m_reqmsgcache;
};

extern std::unique_ptr<ConnectionPool> g_conn_pool;
