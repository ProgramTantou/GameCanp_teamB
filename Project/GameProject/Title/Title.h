#pragma once
#include "../Game/Task.h"

class Title :public Task {
private:
	CImage m_img;
public:
	int select_mode;//���ݑI�𒆂̃��[�h

	Title(const CVector2D& pos);
	void Update() override;
	void Render() override;
};