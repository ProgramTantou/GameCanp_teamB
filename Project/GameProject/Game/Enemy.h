#pragma once
#include "../Base/Base.h"

extern TexAnimData enemy_anim_data[];
class Enemy : public Base {
public:
	Enemy(const CVector3D& p);
	void Update();
	void Draw();
	void Collision(Base* b);

private:
	CImage m_img;
	bool m_flip;
	int move_dir;


};
