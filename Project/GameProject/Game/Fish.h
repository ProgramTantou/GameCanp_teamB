#pragma once
#include"Base/Base.h"

class Fish :public Base {
private:
	CImage m_img;
public:
	Fish(const CVector2D& pos,int fish);
	//‹›‚Ìí—Ş
	int m_fish;
	//XV
	void Update();
	//•`‰æ
	void Draw();
	//Õ“Ë”»’è
	void Collision(Base* b);
};