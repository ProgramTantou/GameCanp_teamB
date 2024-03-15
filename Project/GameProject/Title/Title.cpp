#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"

Title::Title() : ObjectBase(eType_Title) {
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	new Casol(CVector2D(950, 600));
	//変数一覧
	int select_mode = 1;//現在選択中のモード
}

Title::~Title()
{
	new Game();
}

void Title::Update() {
	
	//スペースキーでＧＡＭＥを生成し、ゲームスタートする。
		if (PUSH(CInput::eButton5) )
		{
			Kill();
		}
}

void Title::Render() {
	m_img.SetPos(900,500);
	m_img.Draw();
}
