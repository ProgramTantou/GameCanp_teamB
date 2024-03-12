#pragma once
#include"../Base/Base.h"
#include "ObjectBase.h"
#include "CharaBase.h"

extern TexAnimData player_anim_data[];
class Player : public ObjectBase {
private:
	CImage m_img;
	bool m_is_ground;
	int m_attack_no;
	//int m_damage_no;
	//int m_hp;

public:
	Player();
	
	// CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	void Update() override;
	void Move();
	void Attack();
	void Render() override;
	void Collision(Task* b) override;

	//void Death() override;
};