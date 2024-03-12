#pragma once
#include"Task.h"

class Shadow :public Task 
{
public:

	Shadow();
	~Shadow();

	void Update()override;
	void Render()override;



private:
	CImage* mp_image;
};
