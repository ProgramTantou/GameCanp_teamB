#include "Fade.h"

Fade::Fade() : Task(eType_Scene, (int)TaskPrio::Fade) {
	time = 0;
	Arufa = 0.00;
	Arufa_flag = false;
}

void Fade::Update() {
	if(Arufa_flag == false && Arufa < 1.00){
		Arufa += 0.05;
	}

	if (Arufa >= 1.0) {
		time++;
		if (time == 120){
			Arufa_flag = true;
			time = 0;
		}
	}
	
	if (Arufa_flag == true) {
		Arufa -= 0.05;
		if (Arufa <= 0.00) {
			Kill();
		}
	}
}

void Fade::Render() {
	Utility::DrawQuad(CVector2D(0, 0), CVector2D(SCREEN_WIDTH, SCREEN_HEIGHT), CVector4D(0, 0, 0, Arufa));
}