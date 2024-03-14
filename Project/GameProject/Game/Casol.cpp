#include "Casol.h"
#include "Game.h"

Casol::Casol(const CVector2D& p) : ObjectBase(eType_UI) {
	m_img = COPY_RESOURCE("Cursor", CImage);
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	select_mode = 1;
	m_pos.x = 600;
	m_pos.y = 900;
}

void Casol::Update() {
	//モード選択処理
		if (PUSH(CInput::eRight))
		{
			m_pos.x += 400;
			select_mode += 1;
		}
	
	if (select_mode > 3)
	{
		if (PUSH(CInput::eRight))
		{
			select_mode = 1;
			m_pos.x = 600;
		}
	}

		if (PUSH(CInput::eLeft))
		{
			m_pos.x -= 400;
			select_mode -= 1;
		}
		if (select_mode < 1)
		{
			if (PUSH(CInput::eLeft))
			{
				select_mode = 3;
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
		default:
			break;
		}
	}

void Casol::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}