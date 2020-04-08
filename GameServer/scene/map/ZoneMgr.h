#pragma once
#include "GameDef.h"
#include "Zone.h"
#include <memory>
#include <vector>

struct ZoneInfo
{
	ZoneInfo()
	{
		m_xsize = 0;
		m_zsize = 0;
		m_size = 0;
		m_mapxlen = 0.0f;
		m_mapzlen = 0.0f;
	}
	int32_t m_xsize;
	int32_t m_zsize;
	int32_t m_size;
	float m_mapxlen;
	float m_mapzlen;
};

struct ZoneRect
{
	ZoneRect()
	{
		sx = ex = sz = ez;
	}
	int32_t sx;
	int32_t ex;
	int32_t sz;
	int32_t ez;
	bool IsInRect(int32_t x, int32_t z)
	{
		if (x >= sx && x <= sz && z >= sz && z <= ez)
		{
			return true;
		}
		return false;
	}
};

enum EZoneRange
{
	E_ZONE_ZERO = 0,   // ������
	E_ZONE_ONE = 1,    // 9 ����
	E_ZONE_TWO = 2,    // 25 ����
};

class Obj;
using zone_ids_t = std::vector<int32_t>;
using zone_obj_t = std::vector<Obj*>;
using zone_zones_t = std::vector<Zone>;
class ZoneMgr
{
public:
	ZoneMgr(){}
	~ZoneMgr(){}
	bool Init(int32_t mapxlen, int32_t mapzlen, int32_t zonesize);
	void Clear();

	bool EnterZone(Obj* obj, int32_t zoneid, EZoneRange range = E_ZONE_ZERO); // ��ҽ��볡�����ӣ��������ڵ�ͼ�ϳ�ʼ��-���볡���� ֪ͨ������Χ���
	bool LeaveZone(Obj* obj, int32_t zoneid, EZoneRange range = E_ZONE_ZERO); // ��ҴӸ���ɾ�����뿪������������ ֪ͨ������Χ���
	bool ChangeZone(Obj* obj, int32_t oldzoneid, int32_t newzoneid, EZoneRange range = E_ZONE_ZERO);// ����ڵ�ͼ���߶����ƶ�����һ������(�����������ң����뿪��������Ұ��֪ͨ������������Ұ)

private:
	set_player_t GetZonePlayerList(int32_t zoneid, EZoneRange range = E_ZONE_ZERO);
	ZoneRect GetZoneRect(int32_t zoneid, EZoneRange range = E_ZONE_ZERO);
	zone_ids_t GetZoneIdList(int32_t zoneid, EZoneRange range = E_ZONE_ZERO);
	void GetChangeZoneIdList(int32_t oldzoneid, int32_t newzoneid, zone_ids_t& oldzoneids, zone_ids_t& newzoneids, EZoneRange range = E_ZONE_ZERO);
	void SendMsgLeave(Obj* obj, set_player_t& players);
	void SendMsgEnter(Obj* obj, set_player_t& players);
	void SendMsgToMe(Obj* obj, set_player_t& players);
	void SendMsgToOthers(Obj* obj, set_player_t& players);
private:
	zone_zones_t m_zones;
	ZoneInfo m_zoneinfo;

	int32_t m_zonesize{0};
};

extern std::unique_ptr<ZoneMgr> g_pZoneMgr;