#include "CharaBase.h"

CharaBase::CharaBase(const CVector2D& pos)
	: ObjectBase(pos)
	, m_hp(100)
	, m_is_Death(false)
{

}

CharaBase::~CharaBase()
{

}

void CharaBase::TakeDamage(int damage)
{
	//既にHPが０であれば、ダメージ処理を実行しない。
	if (m_hp <= 0) return;
	m_hp -= damage;
	if (m_hp <= 0)
	{
		//死亡処理
		Death();
	}
}

void CharaBase::Death()
{
	//死亡フラグを立てる
	m_is_Death = true;
}