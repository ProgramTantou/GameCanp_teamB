#pragma once
#include "ObjectBase.h"

class Boss : public ObjectBase {
public:
	Boss(const CVector3D& pos,bool flip);
	void Update()override;
	void Render()override;
	void Attack();
	int GetHP();
	int attack_no;

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