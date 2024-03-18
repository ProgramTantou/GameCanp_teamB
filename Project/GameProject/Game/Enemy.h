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
	void GiveScore(int Score);
	void Dead();
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
	int timer;
	int waitTimer;
	int waitdistance;
	int waitduration;
	int ChargingInterval;
	float attack_Timer;
	float attack_Interval;
	float move_speed;
	float move_speed1;
	float move_charg;
	float attack_range;
	bool m_flip;
	bool isCharging;
	
	
	


};
