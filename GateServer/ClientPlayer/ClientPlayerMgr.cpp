#include "ClientPlayerMgr.h"
#include "ClientPlayer.h"
#include "Session.h"
#include "SnowFlake.h"

std::unique_ptr<ClientPlayerMgr> g_pClientPlayerMgr = nullptr;

ClientPlayer* ClientPlayerMgr::NewPlayer(Session* pSession)
{
	if (pSession == nullptr) return nullptr;

	ClientPlayer* player = mClientPool.NewElem();
	if (player == nullptr) return nullptr;
	player->SetSession(pSession);
	player->SetPlayerId(g_pSnowFlake->UniqueId());
	return player;
}

void ClientPlayerMgr::DelPlayer(ClientPlayer* player)
{
	mClientPool.DelElem(player->GetMemId());
	mPlayerSockMap.erase(player->GetSockFd());
	m_playeridMap.erase(player->GetPlayerId());
}

ClientPlayer* ClientPlayerMgr::GetPlayer(int memId)
{
	return mClientPool.GetElem(memId);
}

void ClientPlayerMgr::AddPlayerIDMap(uint64_t playerId, ClientPlayer* player)
{
	if (player == nullptr) return;

	auto it = m_playeridMap.find(playerId);
	if (it == m_playeridMap.end())
	{
		m_playeridMap.emplace(playerId, player);
	}
}
ClientPlayer* ClientPlayerMgr::GetPlayerByID(uint64_t playerId)
{
	auto it = m_playeridMap.find(playerId);
	if (it == m_playeridMap.end()) return nullptr;

	return it->second;
}

void ClientPlayerMgr::AddPlayerSockMap(socket_t sock_fd, ClientPlayer* player)
{
	if (player == nullptr) return;
	auto it = mPlayerSockMap.find(sock_fd);
	if (it == mPlayerSockMap.end())
	{
		mPlayerSockMap.emplace(sock_fd, player);
	}
}

ClientPlayer* ClientPlayerMgr::GetPlayerByFd(socket_t sock_fd)
{
	auto it = mPlayerSockMap.find(sock_fd);
	if (it == mPlayerSockMap.end()) return nullptr;

	return it->second;
}