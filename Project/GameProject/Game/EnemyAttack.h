#pragma once
#include"ObjectBase.h"

class EnemyAttack : public ObjectBase {
public:
	//�R���X�g���N�^
	EnemyAttack(const CVector3D& pos, const int attack_no, int attack, bool flip);
	//�X�V���\�b�h
	void Update() override;
	//�`�惁�\�b�h
	void Render() override;
	//�_���[�W���擾
	int GetDamage()const;
	
	int GetAttackNo() 
	{
		return m_attack_no;
	}
private:
	CImage m_img;
	int m_damage;//�U���̃_���[�W
	float m_rot; //�U���̌���
	int m_attack_no;//�U���ԍ�
	int m_timeout;//�G�̍U����������܂ł̎���
	int m_attack;
	bool m_flip;

};