#pragma once
#include "../Game/Task.h"
#include "../Game/ObjectBase.h"

class Title :public ObjectBase {
private:
	CImage m_img;
public:
	int select_mode=1;//Œ»İ‘I‘ğ’†‚Ìƒ‚[ƒh

	Title();
	void Update() override;
	void Render() override;
};