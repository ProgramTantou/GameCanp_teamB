#pragma once
#include "Task.h"
#include "ObjectBase.h"

class FrontObject : public Task
{
public:
	CImage m_img;

	FrontObject(int type);
	void Update() override;
	void Render() override;

	int front_type = 0;
};