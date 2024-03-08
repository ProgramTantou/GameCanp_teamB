#pragma once
#include"../Base/Base.h"

extern TexAnimData player_anim_data[];
class Player :public Base {
private:
	CImage m_img;
	bool m_is_ground;
	int m_attack_no;
	bool m_flip;
	//int m_damage_no;
	int m_hp;

public:
	Player(const CVector3D& p,bool flip);
	
	// CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	int GetHp();
	void Update();
	void Move();
	void Attack();
	void Draw();
	void Collision(Base* b);
	

};
