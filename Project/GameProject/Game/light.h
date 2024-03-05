#pragma once
#include "../Base/Base.h"
#include "math.h"
#define _USE_MATH_DEFINES

class light :public Base {
private:
	CImage m_img;

public:
	int select_mode;//Œ»İ‘I‘ğ’†‚Ìƒ‚[ƒh
	typedef struct {
		double x;
		double y;
	}Point;

	light(const CVector2D& pos);
	void Update();
	void Draw();

	
};