#pragma once
#include "ObjectBase.h"

class GameOver :public ObjectBase {
private:
	CImage m_img;
public:
	GameOver(const CVector2D& pos);
	void Update() override;
	void Render() override;

	int select_mode = 1;
};