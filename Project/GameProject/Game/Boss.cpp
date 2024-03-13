#include "Boss.h"

Boss::Boss(const CVector3D& pos, bool flip) :ObjectBase(eType_Enemy) {
	m_pos = pos;
	m_flip = flip;
	m_img = COPY_RESOURCE("", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(512, 512);
	m_img.SetCenter(256, 256);
	m_rect = CRect(-256, -256, 256, 256);
	m_hp = 5;
	Timer = 0;
	attack_Timer = 0.0f;
	attack_Interval = 60.0f;
}

int Boss::GetHP() 
{
	return m_hp;
}

void Boss::Update()
{
	

}

void Boss::Render()
{

}