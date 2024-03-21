#pragma once
#include"ObjectBase.h"

class jellyfish_Manager :public ObjectBase {
private:
	int m_cnt;
	int m_cut;
public:
	jellyfish_Manager();
	void Update() override;
};