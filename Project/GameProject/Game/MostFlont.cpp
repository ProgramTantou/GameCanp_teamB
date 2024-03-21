#include "MostFront.h"

MostFront::MostFront(int Field_Number) : ObjectBase(eType_MostFront) {
	Field_number = Field_Number;
	count = 0;
	count2 = 0;
	switch (Field_number) {
	case 1:
		mp_image_Light = COPY_RESOURCE("Light_1", CImage);
		mp_image_Underwater = COPY_RESOURCE("Underwater_1", CImage);
		break;
	case 2:
		mp_image_Light = COPY_RESOURCE("Light_2", CImage);
		mp_image_Underwater = COPY_RESOURCE("Underwater_2", CImage);
		break;
	default:
		break;
	}
}

void MostFront::Update() {
	count++;
	count2++;
}

void MostFront::Render() {
	float sc;
	sc = ObjectBase::m_scroll.x + sin(DtoR(count)) * 16;
	mp_image_Underwater.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Underwater.Draw();

	sc = ObjectBase::m_scroll.x;
	mp_image_Light.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Light.SetColor(1, 1, 1, 0.2 + sin(DtoR(count2)) * 0.1);
	mp_image_Light.Draw();
}