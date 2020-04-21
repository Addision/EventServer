#include "LoginPlayer.h"
#include "LogUtil.h"
#include "Assertx.h"
#include "Connection/ConnectionPool.h"
#include "NodeNet/LoginServerThread.h"
#include "redis/db_redis.h"
#include "client/login/HandleLogin.h"

int HandleLogin::LoginReq(Player* player, Packet* packet)
{
	Assert(player && packet);
	auto pb_msg = (Login_LoginReq*)packet->msg;
	auto login_player = (LoginPlayer*)player;
	// unity ��¼ �û���������֤
	// �ֻ��ͻ��˵�¼ gameid token(openid) channelid ���͵�������֤
	std::thread::id tid = std::this_thread::get_id();
	if (tid == g_pServerThread->GetThreadId())
	{
		if (pb_msg->game_id().empty())
		{
			// ����������֤
			ConnThread* conn_thrd = g_conn_pool->Malloc();
			MsgCache msg_cache;
			msg_cache.m_packet = new Packet();
			msg_cache.m_packet->msg->CopyFrom(*packet->msg);
			msg_cache.m_packet->msg_id = packet->msg_id;
			msg_cache.m_player = login_player;
			msg_cache.m_result = nullptr;

			std::string sql = "select loginname,loginpwd from tb_account where loginname='" + pb_msg->login_name() \
				+ "' and loginpwd='" + pb_msg->login_pwd()+"';";
			msg_cache.m_sql = sql;
			conn_thrd->AddReqMsg(msg_cache);
		}
		else
		{
			// ͨ��sdk ��֤
		}
	}
	else
	{
		ConnThread* conn_thrd = g_conn_pool->GetConnThread(tid);
		if (conn_thrd == nullptr)
		{
			return 0;
		}
		// ���ݿ⴦����
		MsgCache* msg_cache = conn_thrd->GetMsgCache();
		if (msg_cache->m_result)
		{
			LOG_INFO("login ok!!!");
			// TODO : ͨ����֤��1�����û� ����tb_player���ݣ���2�����û������û�����Ϣ
			// ֪ͨ�ͻ��˵�¼��֤�ɹ�
			Login_LoginReply reply;
			reply.set_ret(0);

			g_pServerThread->LoginClient().SendToGate(msg_cache->m_player->m_servid, msg_cache->m_player->m_playerid, msg_cache->m_packet->msg_id, &reply);
			g_pLoginPlayerPool->DelLoginPlayer(msg_cache->m_player);
			DELETE_PTR(msg_cache->m_packet);

		}
	}

	return 0;
}
int HandleLogin::CreateRoleReq(Player* player, Packet* packet)
{

	return 0;
}
int HandleLogin::SelectRoleReq(Player* player, Packet* packet)
{
	// TODO ѡ���ɫ���� ���ص�redis��

	return 0;
}
int HandleLogin::DelRoleReq(Player* player, Packet* packet)
{
	return 0;
}