#pragma once
#include"ObjectBase.h"

class FishManager :public ObjectBase {
private:
	int m_cnt;
	int m_cut;
public:
	FishManager();
	void Update();
};