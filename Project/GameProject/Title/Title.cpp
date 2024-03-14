#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"

Title::Title() : ObjectBase(eType_Title) {
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.Load("Image/title.png");
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	new Casol(CVector2D(950, 600));
	//変数一覧
	int select_mode = 1;//現在選択中のモード
}

void Title::Update() {
	//モード選択処理
	if (PUSH(CInput::eRight))
	{
		select_mode += 1;
	}

	if (select_mode > 3)
	{
		if (PUSH(CInput::eRight))
		{
			select_mode = 1;
		}
	}

	if (PUSH(CInput::eLeft))
	{
		select_mode -= 1;
	}
	if (select_mode < 1)
	{
		if (PUSH(CInput::eLeft))
		{
			select_mode = 3;
		}
	}

	//１でゲームスタート
//２でクレジット
//３でイグジット
		if (PUSH(CInput::eButton5))
		{
			Kill();
		}
}

void Title::Render() {
	m_img.SetPos(900,500);
	m_img.Draw();
}
