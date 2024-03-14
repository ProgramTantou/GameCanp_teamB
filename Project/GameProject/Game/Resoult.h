#pragma once
#include "Task.h"

class Resoult : public Task
{
private:
	CImage m_img;
	CFont m_font;

public:
	Resoult();
	~Resoult();
	void Update() override;
	void Render() override;
};