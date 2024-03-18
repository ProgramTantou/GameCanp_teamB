#pragma once
#include "ObjectBase.h"

class Boss : public ObjectBase {
public:
	Boss(const CVector3D& pos,bool flip);
	void Update()override;
	void Render()override;
	void Attack();
	void Collision(Task* b)override;
	void GiveScore(int Score);
	void Dead();
	int GetHP();
	int attack_no;
	int m_Damage_no;

private:
	CImage m_img;
	int m_Attack_no;
	int m_hp;
	int move_dir;
	float attack_Timer;
	float attack_Interval;
	float Timer;
	bool m_flip;
};