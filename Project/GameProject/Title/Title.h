#pragma once
#include "../Game/Task.h"
#include "../Game/ObjectBase.h"

class Title :public ObjectBase {
private:
	CImage m_img;
public:
	int select_mode=1;//���ݑI�𒆂̃��[�h

	Title();
	void Update() override;
	void Render() override;
};