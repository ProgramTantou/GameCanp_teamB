#pragma once
#include "ObjectBase.h"
#include "AnimData.h"

class seaweed : public ObjectBase
{
private:
	CImage m_img;

public:
	

	seaweed(const CVector3D& pos);

	void Update() override;
	void Render() override;
};

