#pragma once
#include "../Base/Base.h"

class Title :public Base {
private:
	CImage m_img;
public:
	int select_mode;//Œ»İ‘I‘ğ’†‚Ìƒ‚[ƒh

	Title(const CVector2D& pos);
	void Update();
	void Draw();
};