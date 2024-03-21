#pragma once
#include "Task.h"

class FrontObject : public Task
{
public:
	CImage m_img;

	FrontObject();
	void Update() override;
	void Render() override;

};