#pragma once
#include <string>

class Table
{
public:
private:
};

// ��Ӧ���ݿ��
struct tb_account
{
	int id;
	std::string loginname;
	std::string loginpwd;
	std::string gameid;
	std::string openid;
	std::string token;
	std::string channelid;
	std::string whitelist;
	std::string snid;
	std::string mac;
};

struct tb_player
{
	int64_t playerid;
	std::string gameid;
	int roleid;
	std::string nickname;
	int sex;
	int level;
	std::string create_tm;
	std::string online_tm;
	std::string offline_tm;
	int gold;
	std::string guildid;
};