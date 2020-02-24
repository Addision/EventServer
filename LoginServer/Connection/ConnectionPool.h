#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "ThreadBase.h"
#include "Conn.h"

class ConnThread;
class LoginPlayer;
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
	using sqlquery_t = std::map<uint64_t, std::string>;
	using sqlresult_t = std::map<uint64_t, MariaCpp::ResultSet*>;
	using players_t = std::map<uint64_t, LoginPlayer*>;
public:
	bool Init();
	bool Init(LoginPlayer* player);
	void ThreadLoop();
	void AddSqlReq(uint64_t playerid, const std::string& sql);
	bool IsFree() { return m_sqlquery.size()==0; }
	int GetReqSize() { return m_sqlquery.size(); }
	void GetQueryRes(uint64_t playerid, result_t& result);
private:
	bool Query(uint64_t playerid, const std::string& sql);
private:
	Conn m_conn;
	sqlquery_t m_sqlquery;
	sqlresult_t m_sqlresult;

	players_t m_players;
};

extern std::unique_ptr<ConnectionPool> g_conn_pool;
