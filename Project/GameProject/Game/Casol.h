#pragma once
#include "ObjectBase.h"

class Casol :public ObjectBase{
private:
	CImage m_img;

public:
	int select_mode=0;//Œ»İ‘I‘ğ’†‚Ìƒ‚[ƒh

	Casol(const CVector2D& pos);
	void Update() override;
	void Render() override;
};