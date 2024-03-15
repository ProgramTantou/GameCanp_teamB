#pragma once
#include "Task.h"

class Shadow : public  Task {
private:
	CImage m_img;

public:

	Shadow();
	void Update() override;
	void Render() override;
};