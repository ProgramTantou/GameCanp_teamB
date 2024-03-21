#pragma once
#include "Task.h"
#include "ObjectBase.h"

class FrontObject : public Task
{
public:
	CVector2D m_pos;

	CImage m_img;

	FrontObject(int type);
	void Update() override;
	void Render() override;
	void SetPos(const CVector2D& pos);

	int front_type = 0;
};

extern TexAnimData seaweedA[];