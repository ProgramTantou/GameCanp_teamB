#pragma once
#include "ObjectBase.h"

class Shadow :public  ObjectBase {
private:
	CImage m_img;

public:
	int select_mode = 1;//���ݑI�𒆂̃��[�h

	Shadow(const CVector2D& pos);
	void Update() override;
	void Render() override;
};