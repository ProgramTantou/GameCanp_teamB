#pragma once
#include"ObjectBase.h"

class FishManager :public ObjectBase {
private:
	int m_cnt;
public:
	FishManager();
	void Update();
};