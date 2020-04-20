#pragma once
#include <string>
#include "NetProto/db/GameDB.pb.h"
using std::string;

class Table
{
public:
private:
};

// ��Ӧ���ݿ��
struct tb_account
{
	int id;
	string loginname;
	string loginpwd;
	string gameid;
	string openid;
	string token;
	string channelid;
	string whitelist;
	string snid;
	string mac;
};

struct tb_Role
{
	// ���û������� 
	uint64_t	role_id;	// ��ɫID
	string	account;	// �˺�
	string	role_name;	// ����
	int32_t	role_sex;	// �Ա�
	int32_t	role_isvalid; // ��ɫ�Ƿ���Ч
	int64_t	tm_login;	// ��¼ʱ��
	int64_t	tm_logout;	// �˳�ʱ��
	float	scene_id;
	float	pos_x;		// 
	float	pos_z;		//
	float	last_scene_id;	//
	float	last_pos_x;	// 
	float	last_pos_z;	//
	// ս����������
	int32_t	role_hp;
	int32_t	role_mp;
	// ����ģ������
	string	activity_db;
	string	pet_db;
	string	tasks_db;
	string	skill_db;
	string	buff_db;
	string	resource_db;	// ��ɫ��Դ��������Դ���ң�
	string	his_resource_db;	// ��ɫ��Դ����ʷ������Դ���ң�
	string	item_db;
	string	equip_db;
};

void ConvertToPb(tb_Role& role_db, Role& role_pb, bool isjson = false);

void ConvertToTb(Role& role_pb, tb_Role& role_db, bool isjson = false);