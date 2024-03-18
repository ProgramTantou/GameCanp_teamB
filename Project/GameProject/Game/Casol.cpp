#include "Casol.h"
#include "Game.h"

Casol::Casol(const CVector2D& p) : ObjectBase(eType_UI) {
	m_img = COPY_RESOURCE("Cursor", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	select_mode = 1;
	m_pos.x = 300;
	m_pos.y = 900;
}

void Casol::Update() {
	//cnt減少処理
	if (cnt > 0)
	{
		cnt--;
	}

	//セレクトモードが２の時にスペースキーでＧＡＭＥを生成し、ゲームスタートする。
	if (selectOK)
	{
		//モード選択処理
		if (PUSH(CInput::eRight))
		{
			m_pos.x += 700;
			select_mode += 1;
		}

		if (select_mode > 2)
		{
			if (PUSH(CInput::eRight))
			{
				select_mode = 1;
				m_pos.x = 300;
			}
		}

		if (PUSH(CInput::eLeft))
		{
			m_pos.x -= 700;
			select_mode -= 1;
		}
		if (select_mode < 1)
		{
			if (PUSH(CInput::eLeft))
			{
				select_mode = 2;
				m_pos.x = 1000;
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
			if (PUSH(CInput::eButton5) && cnt == 0 && selectOK)
			{
				selectOK = false;
				cnt = 30;
			}
			break;

		default:
			break;
		}
	}
	if (PUSH(CInput::eButton5) && selectOK == false && cnt == 0)
	{
		selectOK = true;
		cnt = 30;
		//select_mode = 1;
	}
}

void Casol::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}