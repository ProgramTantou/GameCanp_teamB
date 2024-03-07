#include "CharaBase.h"

//�R���X�g���N�^
CharaBase::CharaBase(const CVector2D& pos)
	:ObjectBase(pos)
	,m_hp(100)
	,m_isDeath(false)
{

}

//�f�X�g���N�^
CharaBase::~CharaBase()
{

}

//�_���[�W���󂯂�
void CharaBase::TakeDamage(int damage)
{
	//���ł�HP��0�ł���΁A�_���[�W���������s���Ȃ�
	if (m_hp <= 0)return;

	//�̂���HP����_���[�W�����Z
	m_hp -= damage;
	//�̂���HP ��0�ł����
	if (m_hp <= 0) 
	{
		//���S����
		Death();
	}
}

//���S�����Ƃ��̏���
void CharaBase::Death()
{
	m_isDeath = true;
}