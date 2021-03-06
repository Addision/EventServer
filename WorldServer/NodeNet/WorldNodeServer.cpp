#include <iostream>
#include "WorldNodeServer.h"
#include "JsonConfig.h"
#include "LogUtil.h"
#include "SeFNodeNet.pb.h"
#include "SeFNet.h"

bool WorldNodeServer::InitHelper()
{
	mNetServModule->AddReceiveCallBack(this, &WorldNodeServer::OtherMessage);

	//init server info
	if (!mNetServModule->InitNet(g_pConfig->m_ServerConf["NodePort"].asUInt()))
	{
		LOG_ERR("init WorldServer failed");
		return false;
	}
	CLOG_INFO << "init WorldServer ok" << CLOG_END;
	return true;
}

void WorldNodeServer::OtherMessage(const socket_t sock_fd, const int msg_id, const char* msg, const size_t msg_len)
{

}

