#pragma once
#include "ObjectBase.h"

//�L�����N�^�[�̃x�[�X�N���X
class CharaBase : public ObjectBase {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="pos">�����ʒu</param>
	CharaBase(const CVector2D& pos);
	//�f�X�g���N�^
	virtual ~CharaBase();

	/// <summary>
	/// �_���[�W���󂯂�
	/// </summary>
	/// <param name="damage">�󂯂�_���[�W��</param>
	void TakeDamage(int damage);

	//���S�������̏���
	virtual void Death();

protected:
	int m_hp;       //�L�����N�^�[�̎c��HP
	bool m_isDeath; //�L�����N�^�[�����S���Ă��邩�ǂ���
};
