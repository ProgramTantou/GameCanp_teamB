#pragma once
#include "ObjectBase.h"

class Resoult : public ObjectBase
{
private:
	CImage m_img;
	CFont m_font;
	int coro = 0;//トゥルーでゲームオーバー。フォルスでゲームクリア。

public:
	Resoult(int CorO);
	~Resoult();
	void Update() override;
	void Render() override;
};