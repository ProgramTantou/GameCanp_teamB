#include "UI.h"
#include "Player.h"

//コンストラクタ
UI::UI(const CVector2D& pos, int UI_Nunber) : Base(eType_UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("HP",CImage);
	//m_img2 = COPY_RESOURCE("Box", CImage);
	hp = 0;
	m_pos = pos;
	UI_number = UI_Nunber;
	switch (UI_number)
	{
	case 1:
		m_img.SetCenter(128, 128);
		m_img.SetSize(256, 256);
		break;
	case 2:
		break;
	}
	m_Rect = 0;
	m_Rect2 = 2489;
};

//デストラクタ
UI::~UI() {

}

//更新処理
void UI::Update() {
	hp = 11 - Player::GetHp();
	if (hp == 8) {
		m_Rect += 2489;
		m_Rect2 += 2489;
	}
}

//描画処理
void UI::Draw() {
	float sc;
	sc = m_scroll.x;
	switch (UI_number) {
	case 1:
		m_img.SetPos(GetScreenPos(m_pos));
		m_img.SetRect(hp * 2489, m_Rect, (hp + 1) * 2489, m_Rect2);
		if (Player::GetHp != 0) {
			m_img.Draw();
		}
		break;
	case 2:
		//m_img2.SetPos(GetScreenPos(m_pos));
		//m_img2.Draw();
		break;
	}
}