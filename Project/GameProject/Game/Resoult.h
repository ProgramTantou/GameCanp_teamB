#pragma once
#include "ObjectBase.h"
#include "TaskManager.h"

class Resoult : public ObjectBase
{
private:
	CImage m_img;
	CFont m_font;
	CFont m_font2;
	int coro = 0; //1�ŃQ�[���I�[�o�[�A2�ŃQ�[���N���A

public:
	Resoult(int CorO);
	~Resoult();
	void Update() override;
	void Render() override;
};