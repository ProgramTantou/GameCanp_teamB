#pragma once
#include "ObjectBase.h"

class MostFront : public ObjectBase {
public:
	CImage mp_image_Light;
	CImage mp_image_Underwater;
	MostFront(int Field_Number);
private:
	void Update();
	void Render();
	int Field_number;
};
