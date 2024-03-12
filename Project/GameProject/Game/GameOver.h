#pragma once
#include "Task.h"

class GameOver :public Task {
private:
	CImage m_img;
public:
	GameOver(const CVector2D& pos);
	void Update() override;
	void Render() override;
};