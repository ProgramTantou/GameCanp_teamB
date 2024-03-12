#pragma once
#include "../Base/Base.h"
#include "CharaBase.h"

extern TexAnimData enemy_anim_data[];
class Enemy : public CharaBase {
public:
	Enemy(const CVector3D& p);
	void Update() override;
	void Render() override;
	void Collision(Base* b);

private:
	CImage m_img;
	bool m_flip;
	int move_dir;


};
