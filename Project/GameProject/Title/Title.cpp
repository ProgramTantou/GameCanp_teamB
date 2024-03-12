#include "Title.h"
/*#include "Title.h"

Title::Title(const CVector2D& p) :Base(eType_Screen) {
	m_img.Load("Image/タイトル画面.png");
	m_rad = 15;
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_pos = p;

	//変数一覧
	int select_mode = 1;//現在選択中のモード

}

void Title::Update() {
	//モード選択処理
	if (select_mode < 4)
	{
		if (PUSH(CInput::eUp))
		{
			select_mode += 1;
		}
		if (select_mode >= 4)
		{
			select_mode = 1;
		}
	}
}

void Title::Draw() {
	m_img.SetPos(m_pos.x,m_pos.y);
	
	m_img.Draw();
}*/

Title::Title(const CVector2D& pos) : Task(eType_Scene, (int)TaskPrio::Scene)
{
}

void Title::Update()
{
}

void Title::Render()
{
}
