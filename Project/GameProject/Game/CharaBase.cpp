#include "CharaBase.h"

CVector2D CharaBase::m_scroll(0, 0);

CharaBase::CharaBase(const CVector2D& pos,int type)
	: ObjectBase(eType_Door)
	,m_hp(100)
	, m_is_Death(false)
{

}

CharaBase::~CharaBase()
{

}

void CharaBase::TakeDamage(int damage)
{
	if (m_hp <= 0) return;
	m_hp -= damage;
	if (m_hp <= 0)
	{
		Death();
	}
}

void CharaBase::Death()
{
	m_is_Death = true;
}