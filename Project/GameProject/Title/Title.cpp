#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"

Title::Title() : ObjectBase(eType_Title) {
	//m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_img.Load("Image/title.png");
	new Casol(CVector2D(1000, 600));
	m_img.ChangeAnimation(1, false);
	//変数一覧
	int select_mode = 1;//現在選択中のモード
}

Title::~Title()
{
	new Game();
}

void Title::Update() {
	
	//スペースキーでＧＡＭＥを生成し、ゲームスタートする。
	if (PUSH(CInput::eRight))
	{
		select_mode += 1;
	}

	if (select_mode > 2)
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
			select_mode = 2;
		}
	}

	if(select_mode!=2)
	{
		m_img.Load("Image/title.png");
	}

	//１でゲームスタート
//２でクレジット
//３でイグジット
	switch (select_mode)
	{
	case 1:
		if (PUSH(CInput::eButton5))
		{
			Kill();
		}
		break;

	case 2:
		if (PUSH(CInput::eButton5))
		{
			m_img.Load("Image/control_manual.png");
		}
		break;

	default:
		break;
	}
}

void Title::Render() {
	m_img.SetPos(1000, 600);
	m_img.Draw();
}
