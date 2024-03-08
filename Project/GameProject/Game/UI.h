#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	CImage m_img;
	CImage m_img2;
	CFont m_UI_text;
public:
	UI();
	~UI();
	void Update();
	void Draw();
};