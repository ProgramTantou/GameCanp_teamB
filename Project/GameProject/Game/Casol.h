#pragma once
#include "../Base/Base.h"

class Casol :public Base {
private:
	CImage m_img;

public:
	int select_mode;//Œ»İ‘I‘ğ’†‚Ìƒ‚[ƒh

	Casol(const CVector2D& pos);
	void Update();
	void Draw();
};