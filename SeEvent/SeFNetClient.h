#pragma once

#include <list>
#include <map>

#include "Se.h"
#include "SeFINet.h"


// 这是一个socket客户端管理类
class SeFNetClient
{
public:
	void Init();

	void AddServer(const ConnectData& info);
	void Excute(LOOP_RUN_TYPE run);

	// add call back
	template<typename BaseType>
	void AddReceiveCallBack(EServerType eType, const UINT32 nMsgId, BaseType* pBase, void(BaseType::* HandleReceive)(const socket_t, const int, const char*, const uint32_t))
	{
		NET_RECEIVE_FUNCTOR functor = std::bind(HandleReceive, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
		NET_RECEIVE_FUNCTOR_PTR functorPtr = std::make_shared<NET_RECEIVE_FUNCTOR>(functor);
		AddReceiveCallBack(eType, nMsgId, functorPtr);
	}
	template<typename BaseType>
	void AddReceiveCallBack(EServerType eType, BaseType* pBase, void(BaseType::* HandleReceive)(const socket_t, const int, const char*, const uint32_t))
	{
		NET_RECEIVE_FUNCTOR functor = std::bind(HandleReceive, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
		NET_RECEIVE_FUNCTOR_PTR functorPtr = std::make_shared<NET_RECEIVE_FUNCTOR>(functor);
		AddReceiveCallBack(eType, functorPtr);
	}
	template<typename BaseType>
	void AddEventCallBack(EServerType eType, BaseType* pBase, void(BaseType::* HandleEvent)(const socket_t nFd, const SE_NET_EVENT nEvent, SeNet* pNet))
	{
		NET_EVENT_FUNCTOR functor = std::bind(HandleEvent, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		NET_EVENT_FUNCTOR_PTR functorPtr = std::make_shared<NET_EVENT_FUNCTOR>(functor);
		AddEventCallBack(eType, functorPtr);
	}
	// remove call back
	void RemoveReceiveCallBack(EServerType eType, UINT32 nMsgId);
	// send msg
	void SendByServerId(int nServerId, const int nMsgID, const char* msg, int len);
	void SendByServerIds(std::vector<int>& nServerIds, const int nMsgID, const char* msg, int len);
	void SendProtoBuffer(int nServerId, const int nMsgID, ::google::protobuf::Message* pMsg);
	void SendProtoBuffer(std::vector<int>& nServerIds, const int nMsgID, ::google::protobuf::Message* pMsg);
	void SendToAll(const int nMsgID, const char* msg, int len);
	void SendToAll(const int nMsgID, ::google::protobuf::Message* pMsg);

private:
	void AddReceiveCallBack(EServerType eType, UINT32 nMsgId, NET_RECEIVE_FUNCTOR_PTR functorPtr);
	void AddReceiveCallBack(EServerType eType, NET_RECEIVE_FUNCTOR_PTR functorPtr);
	void AddEventCallBack(EServerType eType, NET_EVENT_FUNCTOR_PTR functorPtr);
	void OnSocketEvent(const socket_t nFd, const SE_NET_EVENT nEvent, SeNet* pNet);
	void OnSocketConnect(const socket_t nFd, SeNet* pNet);
	void OnSocketDisConnect(const socket_t nFd, SeNet* pNet);
	void ProcessExcute(LOOP_RUN_TYPE run);
	void ProcessAddConnect();
	void InitCallBacks(ConnectData& data);
private:
	struct CallBack
	{
		// msgid handle function
		std::map<int, NET_RECEIVE_FUNCTOR_PTR> mReceiveCallBack;
		std::list<NET_RECEIVE_FUNCTOR_PTR> mCallBackList;
		std::list<NET_EVENT_FUNCTOR_PTR> mEventCallBackList;
		
	};
	// ServerType callback
	std::map<int, CallBack> mmCallBack;

	std::list<ConnectData> mTemplist;
	// serverid connect data
	std::map<int, ConnectData> mConnecServers;
};

