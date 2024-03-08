#pragma once
#include"Base/Base.h"

class Fish :public Base {
private:
	CImage m_img;
public:
	Fish(const CVector2D& pos,int fish);
	void Update();
	void Draw();
	void Collision(Base* b);
};