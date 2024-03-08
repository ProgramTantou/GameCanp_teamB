#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	CImage m_img;
	CImage m_img2;
public:
	void Update();
	void Draw();
};