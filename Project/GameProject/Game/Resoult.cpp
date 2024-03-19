#include "Resoult.h"
#include "GameData.h"
#include "Title/Title.h"
#include "ObjectBase.h"

Resoult::Resoult(int CorO) : ObjectBase(eType_Title),m_font("HGRPP1.TTC",50)
{
	m_img = COPY_RESOURCE("Resoult", CImage);
	m_img.SetSize(1000, 1000);
	m_img.SetCenter(500, 500);
	coro = CorO;
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
	//コンストラクタに渡した引数が１ならゲームオーバー。２ならゲームクリアを表示する。
	if (coro == 1)
	{
		m_font.Draw(800, 350, 0.0, 0.0, 5.0, "ゲームオーバー");
	}
	else if (coro == 2)
	{
		m_font.Draw(800, 350, 5.0, 0.0, 0.0, "ゲームクリア");
	}

	m_font.Draw(900, 500, 2.0, 1.0, 1.0, "スコア");
	m_font.Draw(950, 550, 2.0, 1.0, 1.0, "%d", GameData::m_score);
	m_img.SetPos(960, 540);
	m_img.Draw();
}
