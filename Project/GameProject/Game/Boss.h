#pragma once
#include "ObjectBase.h"

class Boss : public ObjectBase {
public:
	Boss(const CVector3D& pos,bool flip);
	~Boss();
	void Update()override;
	void Render()override;
	void Attack();
	void Collision(Task* b)override;
	void GiveScore(int Score);
	void Dead();
	void Move();
	void Move1();
	void Move2();
	void Action();
	int GetHP();
	int attack_no;
	int m_Damage_no;
	int m_state;

private:
	CImage m_img;
	int m_Attack_no;
	int m_hp;
	int move_dir;
	int randamAction;
	int interval;
	int intervalmax;
	float attack_Timer;
	float attack_Interval;
	float Timer;
	float DropTimer;
	bool m_flip;

	enum {
		eStete_Move,
		eState_Attack,
		eState_Damage,
		eState_Dead,
	};
};