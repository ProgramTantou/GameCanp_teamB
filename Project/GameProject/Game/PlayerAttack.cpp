#include"PlayerAttack.h"
#include"AnimData.h"
#include"Enemy.h"

PlayerAttack::PlayerAttack(const CVector3D& pos, bool flip,int attack_no) :ObjectBase(eType_Player_near) {
	//m_img = COPY_RESOURCE("Effect", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(128, 128);
	m_img.SetCenter(128 / 2, 128 / 1);
	m_rect = CRect3D(-128 / 2, -128 / 1, 128 / 1, 128 / 2, 128 / 1, -128 / 1);
	m_img.ChangeAnimation(0, false);
	m_attack_no = attack_no;
}

void PlayerAttack::Update() 
{
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd())
	{
		Kill();
	}
}

void PlayerAttack::Render() 
{
	m_img.SetPos(GetScreenPos(m_pos));
	//m_img.SetFlipH(m_flip);
	//m_img.Draw();
	DrawRect();
}


