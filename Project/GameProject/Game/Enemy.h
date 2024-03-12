#pragma once
#include "../Base/Base.h"

extern TexAnimData enemy_anim_data[];
class Enemy : public Base {
public:
	Enemy(const CVector3D& p,int enemy_number,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
	void Attack();
	int GetHP();
	int attack_no;

	//�G�̎��
	int Enemy_Number;
private:
	CImage m_img;
	//�U���ԍ�
	int m_Attack_no;
	int m_Damage_no;
	int m_hp;
	int move_dir;
	float attack_Timer;
	float attack_Interval;
	bool m_flip;
	


};
