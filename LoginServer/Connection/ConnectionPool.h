#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "ThreadBase.h"
#include "Conn.h"

class ConnThread;

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
private:
	int m_conn_num;   //conn thread num
	std::vector<ConnThread*> m_conn_threads;
};

class ConnThread : public ThreadBase
{
	using sqlqueue_type = std::map<std::string, std::string>;
public:

	bool Init();
	void ThreadLoop();
	bool IsFree();
	void AddSqlReq(const std::string& playerid, std::string& sql);
	bool Execute(const std::string& sql);

	int GetReqSize() { return m_sqlqueue.size(); }

private:
	Conn m_conn;
	sqlqueue_type m_sqlqueue;
};

extern std::unique_ptr<ConnectionPool> g_conn_pool;
