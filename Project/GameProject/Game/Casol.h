#pragma once
#include "ObjectBase.h"

class Casol :public  ObjectBase{
private:
	CImage m_img;

public:
	int select_mode=1;//現在選択中のモード
	int cnt = 0;//この数字が１以上だと、カーソルを操作できない。

	bool selectOK = true;//これがtrueの間モードを選択できる。

	Casol(const CVector2D& pos);
	void Update() override;
	void Render() override;
};