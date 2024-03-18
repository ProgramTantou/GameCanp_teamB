#include "GameOver.h"
#include"Game.h"
#include"Casol.h"
#include"Player.h"
#include"Enemy.h"
#include"Field.h"
#include"UI.h"
#include"GameData.h"
#include "TaskManager.h"
#include "../Title/Title.h"

GameOver::GameOver(const CVector2D& p) : ObjectBase(eType_Title) {
	m_img.Load("Image/gameover.png");
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	select_mode = 1;
}

GameOver::~GameOver()
{
	//タイトルへ戻る
	new Title();
	//new UI(CVector2D(10, 120), 1);
}

void GameOver::Update() {
	//リトライ
		if (PUSH(CInput::eButton5))
		{
			Kill();
		}
}

void GameOver::Render() {

	FONT_T()->Draw(800, 1000, 1.0f, 0.0f, 0.0f, "あなたのスコア　%d", select_mode);
	m_img.SetPos(950,500);
	m_img.Draw();
}