#pragma once
#include <thread>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include "MapNav.h"

class Scene;
using scene_ptr_t = std::shared_ptr<Scene>;
// ʹ�ö��̼߳��ص�ͼ������Ϣ
class SceneMap
{
public:
	void Start(const std::string mapfile);
	MapNav* GetMapNav() { return &m_map_nav; }
private:
	void LoadMap(const std::string mapfile);
private:
	std::thread m_thread;
	MapNav m_map_nav;
};


