#pragma once
#include "ObjectBase.h"

//extern TexAnimData enemy_anim_data[];
class Enemy : public ObjectBase {
public:
	Enemy(const CVector3D& p,int enemy_number,bool flip);
	void Update() override;
	void Render() override;
	void Collision(Task* b) override;
	void Attack();
	void EnemyMove();
	void EnemyMove1();
	void EnemyMove2();
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
	int deathtimer;
	int waitTimer;
	int waitdistance;
	int waitduration;
	int ChargingInterval;
	int m_state;
	int count;
	float randomX;
	float randomY;
	float attack_Timer;
	float attack_Interval;
	float move_speed;
	float move_speed1;
	float move_charg;
	float attack_range;
	bool m_flip;
	bool isCharging;
	
	enum {
		eState_Move,
		eState_Attack01,
		eState_Attack02,
		eState_Attack03,
		eState_Damage,
		eState_Down
	};
	
};
