#pragma once

#include "SeFINet.h"

class SeFNetClient;

class NetClientBase
{
public:
	virtual bool Init();
	virtual void InitHelper() = 0;
	virtual void SetServerInfoReport() = 0;
	virtual void AddConnectServer() = 0;
	virtual void OnMasterMessage(const socket_t nFd, const int nMsgID, const char* msg, const UINT32 nLen);
	virtual void Loop();

	virtual void OnSocketNodeEvent(const socket_t nFd, const SE_NET_EVENT nEvent, SeNet* pNet);

	ConnectDataPtr GetServerNetInfo(const int nServerID);
	ConnectDataPtr GetServerNetInfo(const SeNet* pNet);

	virtual EServerType GetServerType()
	{
		return (EServerType)mServerReport.server_type();
	}
	virtual void AddConnectMaster();

protected:
	SeFNetClient* mpNetClientModule{ nullptr };
	SeFNetProto::ServerReport mServerReport;
	std::vector<EServerType> mConnectType;
};

