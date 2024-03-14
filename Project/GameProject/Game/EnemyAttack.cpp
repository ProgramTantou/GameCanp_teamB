#include "EnemyAttack.h"

EnemyAttack::EnemyAttack(const CVector3D& pos, const int attack_no, int attack, bool flip):ObjectBase(eType_Enemy_Attack)
{	
	m_pos = pos;
	m_flip = flip;
	m_attack = attack;
	switch (m_attack)
	{
		{case 0:
		{
			//m_img = COPY_RESOURCE("", CImage);
			m_timeout = 0;
			m_damage = 1;
			const CVector2D size(0.0f, 0.0f);
			//m_img.SetPos(GetScreenPos(m_pos));
			//m_img.SetSize(128,128);
			//m_img.SetCenter(128,128);
			m_rect = CRect(-30, -30, 0, 30);
			m_attack_no = attack_no;
		}
		break;
		}
		{case 1:
		{
			//m_img = COPY_RESOURCE("", CImage);
			m_timeout = 0;
			m_damage = 1;
			const CVector2D size(0.0f, 0.0f);
			//m_img.SetPos(GetScreenPos(m_pos));
			//m_img.SetSize(128,128);
			//m_img.SetCenter(128,128);
			m_rect = CRect(-200, -30, 0, 15);
			m_attack_no = attack_no;
		}
		break;
		}
	}
	
}

void EnemyAttack::Update() {
	switch (m_attack)
	{
	case 0:
	{
		static const float moveSpeed = 5.0f;
		if (m_flip)
		{
			m_pos.x += moveSpeed;
		}
		else m_pos.x -= moveSpeed;

		if (m_timeout >= 150)
		{
			Kill();
		}
		else
		{
			m_timeout++;
		}
		break;
	}
	case 1:

		if (m_timeout >= 10) {
			Kill();
		}
		else
		{
			m_timeout++;
		}
		break;
	case 2:
	{

	}
	}
}

void EnemyAttack::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	//m_img.SetFlipH(m_flip);
	//m_img.Draw();
	DrawRect();
}

int EnemyAttack::GetDamage() const
{
	return m_damage;
}
