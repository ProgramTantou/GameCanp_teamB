#pragma once
#include "ObjectBase.h"

extern TexAnimData enemy_anim_data[];
class Enemy : public ObjectBase {
public:
	Enemy(const CVector3D& p,int enemy_number,bool flip);
	void Update() override;
	void Render() override;
	void Collision(Task* b) override;
	void Attack();
	int GetHP();
	int attack_no;

	//“G‚Ìí—Ş
	int Enemy_Number;
private:
	CImage m_img;
	//UŒ‚”Ô†
	int m_Attack_no;
	int m_Damage_no;
	int m_hp;
	int move_dir;
	float attack_Timer;
	float attack_Interval;
	bool m_flip;
	


};
