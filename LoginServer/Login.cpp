#include "Login.h"
#include "NodeNet/LoginServerThread.h"
#include "tablecpp/TableMgr.h"
#include "Session.h"
#include "Connection/ConnectionPool.h"
#include "redis/db_redis.h"
#include "client/login/HandleLogin.h"
#include "JsonConfig.h"
#include "packet/PacketMgr.h"
#include "MsgHandle/LoginPlayer.h"

Login::Login()
{

}
Login::~Login()
{

}

void Login::Init()
{
	g_pTableMgr = std::make_unique<TableMgr>();
	g_pServerThread = std::make_unique<LoginServerThread>();
	g_pSessionPool = std::make_unique<SessionPool>();
	g_conn_pool = std::make_unique<ConnectionPool>();
	g_pRedis = std::make_unique<db_redis>();
	g_pPacketMgr = std::make_unique<PacketMgr>();
	g_pLoginPlayerPool = std::make_unique<LoginPlayerPool>();
	InitManager();
}

void Login::Start()
{
	g_pServerThread->Start();
}

void Login::Stop()
{
	g_pServerThread->Stop();
	g_conn_pool->Stop();
}

void Login::InitManager()
{
	g_conn_pool->Init();
	g_pRedis->init(g_pConfig->m_RedisConf["ConnNum"].asInt(), 
		g_pConfig->m_RedisConf["ip"].asCString(), 
		g_pConfig->m_RedisConf["port"].asInt());

	// register msg
	HandleLogin::Instance();
}