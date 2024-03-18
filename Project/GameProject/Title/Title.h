#pragma once
#include "../Game/Task.h"
#include "../Game/ObjectBase.h"

class Title :public ObjectBase {
private:
	CImage m_img;
public:
	int select_mode=1;//現在選択中のモード

	bool selectOK = true;//これがtrueの間モードを選択できる。

	Title();
	~Title();
	void Update() override;
	void Render() override;
};