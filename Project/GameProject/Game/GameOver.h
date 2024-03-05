#pragma once
#include "../Base/Base.h"

class GameOver :public Base {
private:
	CImage m_img;
public:
	GameOver(const CVector2D& pos);
	void Update();
	void Draw();
};