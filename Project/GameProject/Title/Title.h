#pragma once
#include "../Game/Task.h"
#include "../Game/ObjectBase.h"

class Title :public ObjectBase {
private:
	CImage m_img;
public:
	CFont m_font;
	int select_mode=1;//現在選択中のモード
	int cnt = 0;//この数字が１以上だと、カーソルを操作できない。

	bool selectOK = true;//これがtrueの間モードを選択できる。

	Title();
	~Title();
	void Update() override;
	void Render() override;
};