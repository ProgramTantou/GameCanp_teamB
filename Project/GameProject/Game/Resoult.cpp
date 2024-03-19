#include "Resoult.h"
#include "GameData.h"
#include "Title/Title.h"
#include "ObjectBase.h"

Resoult::Resoult() : ObjectBase(eType_Title)
{
	m_img = COPY_RESOURCE("Resoult", CImage);
	m_img.SetSize(1000, 1000);
	m_img.SetCenter(500, 500);
}

Resoult::~Resoult()
{
	//リザルトでボタンを押すと、タイトルへと戻る。
	new Title();
}

void Resoult::Update()
{
	if (PUSH(CInput::eButton5))
	{
		Kill();
	}
}

void Resoult::Render()
{
	m_font.Draw(940, 400, 2.0, 1.0, 1.0, "スコア");
	m_font.Draw(990, 450, 2.0, 1.0, 1.0, "%d", GameData::m_score);
	m_img.SetPos(960, 540);
	m_img.Draw();
}
