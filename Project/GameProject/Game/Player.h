#pragma once
#include"../Base/Base.h"

extern TexAnimData player_anim_data[];
class Player :public Base {
private:
	CImage m_img;
	//�n�ʂɑ������Ă��邩�̃t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//���]�t���O
	bool m_flip;
	//int m_damage_no;
	//HP�c��
	static int m_hp;

public:
	Player(const CVector3D& p,bool flip);
	
	// CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	 static int GetHp();
	//�X�V
	void Update();
	//�ړ�
	void Move();
	//�_���[�W
	void Damage();
	//�U��
	void Attack();
	//�`��
	void Draw();
	//�Փˏ���
	void Collision(Base* b);
	

};
