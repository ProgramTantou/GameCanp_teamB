#include"FishManager.h"
#include"Fish.h"
#include"Player.h"
#include"TaskManager.h"
#include"GameData.h"

FishManager::FishManager() :ObjectBase(eType_FishManager) {
	m_cnt = 0;
	m_cut = 0;
}

void FishManager::Update() {
	m_cnt--;
	m_cut--;
	if (m_cnt <= 0) {
		new Fish(CVector3D(Utility::Rand(m_scroll.x,m_scroll.x), Utility::Rand(200.0f, 500.0f), Utility::Rand(0.0f, 0.0f)),TaskManager::FindObject(eType_Player), rand() % 3, false, rand(),eType_Fish);
		m_cnt = Utility::Rand(120, 240);
	}
	if (m_cut <= 0) 
	{
		new Fish(CVector3D(Utility::Rand(m_scroll.x+1920, m_scroll.x+1920), Utility::Rand(200.0f, 500.0f), Utility::Rand(0.0f, 0.0f)), TaskManager::FindObject(eType_Player), rand() % 3, true, rand(), eType_Fish);
		m_cut = Utility::Rand(120, 240);
	}

	if (GameData::death_flag == true || GameData::clear_flag == true) 
	{
		Kill();
	}
}