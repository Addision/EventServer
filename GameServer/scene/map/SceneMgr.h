#pragma once
#include <map>
#include <memory>
#include "common/GameDef.h"

class Scene;
class SceneMgr
{
	using scene_t = std::shared_ptr<Scene>;
	// ���� <playerid, scene> ��ʱ����Ϊ��ҵľ�����߸���
	using tmp_scene_t = std::map<int32_t, scene_t>;
	// �������߸��� < sceneid, <lineid, scene> >
	using line_scene_t = std::map<int32_t, scene_t>;
	using scene_mgr_t = std::map<int32_t, line_scene_t>;
public:
	bool LoadAllMap();
	Scene* GetScene(int32_t sceneid, int32_t lineid = 1);
	Scene* CreatTmpScene(uint64_t playerid, ESceneType type);
	Scene* GetTmpScene(uint64_t playerid);
	void DelTmpScene(uint64_t playerid);
private:
	scene_mgr_t m_scene_mgr;
	tmp_scene_t m_tmp_scene;
};

extern std::unique_ptr<SceneMgr> g_pSceneMgr;