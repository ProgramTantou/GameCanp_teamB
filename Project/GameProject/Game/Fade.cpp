#include "Fade.h"

Fade::Fade() : Task(eType_Scene, (int)TaskPrio::Fade) {
	time = 0;
	Arufa = 0.00;
	Arufa_flag = false;
}

void Fade::Update() {
	time++;
	if (Arufa_flag == false && time % 12 == 0) {
		Arufa += 0.1f;
		if (time == 120) {
			time = 0;
			Arufa_flag = true;
		}
	}
	if (Arufa_flag == true && time % 12 == 0) {
		Arufa -= 0.1f;
		if (time == 120) {
			Kill();
		}
	}

}

void Fade::Render() {
	Utility::DrawQuad(CVector2D(0, 0), CVector2D(SCREEN_WIDTH, SCREEN_HEIGHT), CVector4D(0, 0, 0, Arufa));
}