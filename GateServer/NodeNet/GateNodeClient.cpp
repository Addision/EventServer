#include "GateNodeClient.h"
#include "JsonConfig.h"
#include "SeNet.h"
#include "SeFNetClient.h"

void GateNodeClient::InitHelper()
{
	SetReportInfo();
	AddConnectServer();
}

void GateNodeClient::SetReportInfo()
{
	mServerInfo.set_server_id(g_pConfig->m_ServerConf["NodeId"].asInt());
	mServerInfo.set_server_name(g_pConfig->m_ServerConf["NodeName"].asString());
	mServerInfo.set_server_cur_count(0);
	mServerInfo.set_server_ip(g_pConfig->m_ServerConf["NodeIp"].asString());
	mServerInfo.set_server_port(g_pConfig->m_ServerConf["NodePort"].asInt());
	mServerInfo.set_server_max_online(2000);
	mServerInfo.set_server_state(EServerState::EST_NORMAL);
	mServerInfo.set_server_type(ServerType::SERVER_TYPE_GATE);
}

void GateNodeClient::AddConnectServer()
{
	AddConnectMaster();
}

