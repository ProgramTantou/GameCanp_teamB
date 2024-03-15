#pragma once
#include "Task.h"

class Fade : public Task {
private:
	CImage m_img;
	int time;
	float Arufa;
	bool Arufa_flag;
public:
	Fade();
	void Update() override;
	void Render() override;
};
