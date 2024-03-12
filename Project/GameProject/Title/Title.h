#pragma once
#include "../Game/Task.h"

class Title :public Task {
private:
	CImage m_img;
public:
	int select_mode;//Œ»İ‘I‘ğ’†‚Ìƒ‚[ƒh

	Title(const CVector2D& pos);
	void Update() override;
	void Render() override;
};