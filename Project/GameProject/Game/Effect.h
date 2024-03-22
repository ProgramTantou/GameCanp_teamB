#pragma once
#include"ObjectBase.h"

class Effect :public ObjectBase {
private:
	CImage m_img;

	bool m_flip;

public:
	Effect(const char* name, const CVector3D& pos, bool flip);
	void Update();
	void Render();
};