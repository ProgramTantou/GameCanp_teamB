#include"jellyfish_Manager.h"
#include"Fish.h"
#include"Player.h"
#include"TaskManager.h"
#include"GameData.h"
#include "seaweed.h"

jellyfish_Manager::jellyfish_Manager() :ObjectBase(eType_FishManager) {
	m_cnt = 0;
	m_cut = 0;
}

void jellyfish_Manager::Update() {
	m_cnt--;
	m_cut--;
	if (m_cnt <= 0) {
		new seaweed(CVector3D(Utility::Rand(m_scroll.x-100, m_scroll.x-100),700, (Utility::Rand(-150,150))));
		m_cnt = Utility::Rand(120, 240);
	}
	if (m_cut <= 0)
	{
		new seaweed(CVector3D(Utility::Rand(m_scroll.x+1920+400, m_scroll.x+1920+400), 700, (Utility::Rand(-150, 150))));
		m_cut = Utility::Rand(120, 240);
	}

	if (GameData::death_flag == true || GameData::clear_flag == true)
	{
		Kill();
	}
}