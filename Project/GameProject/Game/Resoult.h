#pragma once
#include "ObjectBase.h"

class Resoult : public ObjectBase
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