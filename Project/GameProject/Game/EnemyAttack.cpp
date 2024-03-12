#include "EnemyAttack.h"

EnemyAttack::EnemyAttack(const CVector3D& pos, const int attack_no, int attack, bool flip):ObjectBase(eType_Enemy_Attack)
{	
	m_pos = pos;
	m_flip = flip;
	switch (attack)
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
			m_rect = CRect(-300, -30, 30, 30);
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
			m_rect = CRect(-300, -30, 30, 30);
			m_attack_no = attack_no;
		}
		break;
		}
	}
	
}

void EnemyAttack::Update() {
	if (m_timeout >= 120) {
		Kill();
	}
	else
	{
		m_timeout++;
	}
}

void EnemyAttack::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	//m_img.SetFlipH(m_flip);
	//m_img.Draw();
	//DrawRect();
}

int EnemyAttack::GetDamage() const
{
	return m_damage;
}
