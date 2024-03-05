#include "Casol.h"

Casol::Casol(const CVector2D& p) :Base(eType_Screen) {
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
	}
	else if (select_mode >= 4)
	{
		if (PUSH(CInput::eDown))
		{
			select_mode = 1;
			m_pos.y = 600;
		}
	}

	if (select_mode > 0)
	{
		if (PUSH(CInput::eUp))
		{
			m_pos.y -= 200;
			select_mode -= 1;
		}
		if (select_mode <= 1)
		{
			if (PUSH(CInput::eUp))
			{
				select_mode = 4;
				m_pos.y = 1000;
			}
		}
	}
	
}

void Casol::Draw() {
	m_img.SetPos(m_pos.x, m_pos.y);

	
	m_img.Draw();
}