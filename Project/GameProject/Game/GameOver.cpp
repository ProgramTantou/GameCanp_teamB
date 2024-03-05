#include "GameOver.h"

GameOver::GameOver(const CVector2D& p) :Base(eType_Screen) {
	m_img.Load("Image/ゲームオーバー.png");
	m_rad = 15;
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_pos = p;

	

}

void GameOver::Update() {
	
}

void GameOver::Draw() {
	m_img.SetPos((m_pos));
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}