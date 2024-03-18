#pragma once
#include "ObjectBase.h"

//extern TexAnimData player_anim_data[];
class Player :public ObjectBase{
private:
	CImage m_img;
	//�n�ʂɑ������Ă��邩�̃t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//���]�t���O
	bool m_flip;
	int m_damage_no;
	//HP�c��
	static int m_hp;
	bool damage;
	int i;
	int cnt1;
	int cnt2;
	int cnt3;
	bool player_attack1;

	bool player_attack2;

	bool player_attack3;
	//�_���[�W�󂯂��ۂ̕\������
	int damage_count;
	//�U�����󂯂����̃t���O
	
	int m_damage;
	int m_draw_count;
	int move_speed;
	int jump_pow;
	int m_state;

	enum {
		eState_Move,
		eState_Attack01,
		eState_Attack02,
		eState_Attack03,
		eState_Damage,
		eState_Down
	};
	//�ړ�
	void Move();
	//�_���[�W
	void Damage();
	//�U��
	void Attack01();
	void Attack02();
	void Attack03();
	//��
	void Down();


public:
	Player(const CVector3D& p,bool flip);
	
	// CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	 static int GetHp();
	//�X�V
	void Update() override;
	
	//�`��
	void Render() override;
	//�Փˏ���
	void Collision(Task* b) override;
	//�ő�HP
	static int m_maxhp;

};
