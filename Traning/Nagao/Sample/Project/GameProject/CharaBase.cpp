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
	//����HP���O�ł���΁A�_���[�W���������s���Ȃ��B
	if (m_hp <= 0) return;
	m_hp -= damage;
	if (m_hp <= 0)
	{
		//���S����
		Death();
	}
}

void CharaBase::Death()
{
	//���S�t���O�𗧂Ă�
	m_is_Death = true;
}