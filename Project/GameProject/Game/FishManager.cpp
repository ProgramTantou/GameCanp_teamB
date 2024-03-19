#include"FishManager.h"
#include"Fish.h"
#include"Player.h"
#include"TaskManager.h"

FishManager::FishManager() :ObjectBase(eType_FishManager) {
	m_cnt = 0;
}

void FishManager::Update() {
	m_cnt--;
	if (m_cnt <= 0) {
		new Fish(CVector3D(Utility::Rand(200.0f, 1800.0f), Utility::Rand(200.0f, 800.0f), Utility::Rand(0.0f, 0.0f)),TaskManager::FindObject(eType_Player), rand() % 3, true, rand(),eType_Fish);
		m_cnt = Utility::Rand(120, 180);
	}
}