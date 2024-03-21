#include "Resoult.h"
#include "GameData.h"
#include "Title/Title.h"

Resoult::Resoult(int CorO) : ObjectBase(eType_Title),m_font("HGRPP1.TTC",150),m_font2("HGRPP1.TTC",70)
{
	m_img = COPY_RESOURCE("Resoult", CImage);
	//m_img.SetSize(1000, 1000);
	m_img.SetCenter(565, 540);
	coro = CorO;
}

Resoult::~Resoult()
{
	TaskManager::KillAll();
	new Title();
}

void Resoult::Update()
{
	//スペースボタンを押すと、タイトルへと戻る。
	if (PUSH(CInput::eButton5))
	{
		Kill();
	}
}

void Resoult::Render()
{
	//引数が１ならゲームオーバー、２ならゲームクリアを表示
	if (coro == 1)
	{
		m_font.Draw(450, 250, 0.0, 0.0, 5.0, "ゲームオーバー");
	}
	else if (coro == 2)
	{
		m_font.Draw(520, 250, 5.0, 0.0, 0.0, "ゲームクリア");
	}

	m_font2.Draw(865, 560, 2.0, 1.0, 1.0, "スコア");
	m_font2.Draw(950, 630, 2.0, 1.0, 1.0, "%d", GameData::m_score);
	m_font2.Draw(790, 780, 2.0, 1.0, 1.0, "最高スコア");
	m_font2.Draw(950, 850, 2.0, 1.0, 1.0, "%d", GameData::m_max_score);
	m_img.SetPos(960, 540);
	m_img.Draw();
}
