#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"
#include "Game/Resoult.h"
#include "Game/seaweed.h"
#include "Game/FrontObject.h"
#include "Game/jellyfish_Manager.h"

Title::Title() : ObjectBase(eType_Title) {
	//m_img = COPY_RESOURCE("Title", CImage);
	m_pos.x = 600;
	m_pos.y = 1000;
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_img.Load("Image/title.png");
	//new Casol(CVector2D(1000, 600));
	//変数一覧
	select_mode = 1;//現在選択中のモード
	selectOK = true;
	cnt = 0;
}

Title::~Title()
{
	new Game();//リザルトテストプレイ用に、一時的にタイトル開始時にリザルトが出るようにします。
	new seaweed(CVector3D(500, 700, 0));
	new seaweed(CVector3D(500, 700, 0));
	new seaweed(CVector3D(500, 700, 0));
	new FrontObject(eType_coral);
	new jellyfish_Manager();
	//new Resoult(2);

}

void Title::Update() {

	if (PUSH(CInput::eButton2))
	{
		Kill();
	}

	if (PUSH(CInput::eButton3))
	{
		m_img.Load("Image/control_manual.png");
	}

	/*
	//cnt減少処理
	if (cnt > 0)
	{
		cnt--;
	}

	//セレクトモードが２の時にスペースキーでＧＡＭＥを生成し、ゲームスタートする。
	if (selectOK)
	{
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
		if (PUSH(CInput::eButton5) && cnt==0 && selectOK)
		{
			selectOK = false;
			cnt = 30;
			m_img.Load("Image/control_manual.png");
		}
		break;

	default:
		break;
	}

	//セレクトモードが２の時は、スペースキーを押せば再びセレクトできる。
		if (PUSH(CInput::eButton5) && selectOK==false && cnt==0)
		{
			selectOK = true;
			cnt = 30;
			m_img.Load("Image/title.png");
			//select_mode = 1;
		}
		*/
}

void Title::Render() {
	m_img.SetPos(1000, 600);
	m_img.Draw();
}