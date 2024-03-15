#include "Fade.h"

Fade::Fade() : Task(eType_Scene, (int)TaskPrio::Fade) {
	time = 0;
	Arufa = 0.00;
	Arufa_flag = false;
}

void Fade::Update() {
	time += 10;
	if (Arufa_flag == false && time % 18 == 0) {
		Arufa += 0.01f;
		if (time == 1800) {
			time = 0;
			Arufa_flag = true;
		}
	}
	if (Arufa_flag == true && time % 18 == 0) {
		Arufa -= 0.01f;
		if (time == 1800) {
			Kill();
		}
	}

}

void Fade::Render() {
	Utility::DrawQuad(CVector2D(0, 0), CVector2D(SCREEN_WIDTH, SCREEN_HEIGHT), CVector4D(0, 0, 0, Arufa));
}