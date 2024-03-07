#include"CharaBase.h"
//�R���X�g���N�^
CharaBase::CharaBase(const CVector2D& pos) :ObjectBase(pos), m_hp(100), m_isDeath(false) {

}
//�f�X�g���N�^
CharaBase::~CharaBase() {

}
//�_���[�W���󂯂�
void CharaBase::TakeDamege(int damage) {

    //���ł�HP���O�Ȃ�A�_���[�W���������s���Ȃ�
	if (m_hp <= 0)
	{
		return;
	}
	m_hp -= damage;

	if (m_hp <= 0) {
		Death();
	}
}

//���S�����Ƃ��̏���
void CharaBase::Death() {
	m_isDeath = true;
}