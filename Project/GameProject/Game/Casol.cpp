#include "Casol.h"

Casol::Casol(const CVector2D& p) :Base(eType_Title) {
	m_img.Load("Image/カーソル.png");
	m_rad = 15;
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_pos = p;
}

void Casol::Update() {
	//モード選択処理
	if (select_mode < 4)
	{
		if (PUSH(CInput::eDown))
		{
			m_pos.y += 200;
			select_mode += 1;
		}
		if (select_mode >= 4)
		{
			select_mode = 1;
			m_pos.y = 600;
		}
	}

	if (select_mode > 1)
	{
		if (PUSH(CInput::eUp))
		{
			m_pos.y -= 200;
			select_mode -= 1;
		}
		if (select_mode <= 0)
		{
			select_mode = 4;
			m_pos.y = 200;
		}
	}
	
}

void Casol::Draw() {
	m_img.SetPos((m_pos));
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}