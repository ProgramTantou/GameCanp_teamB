#pragma once
#include "ObjectBase.h"

class Casol :public  ObjectBase{
private:
	CImage m_img;

public:
	int select_mode=1;//���ݑI�𒆂̃��[�h

	Casol(const CVector2D& pos);
	void Update() override;
	void Render() override;
};