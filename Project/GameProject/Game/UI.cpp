#include "UI.h"
#include "Player.h"

//コンストラクタ
UI::UI(const CVector2D& pos, int UI_Nunber) : Base(eType_UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("HP",CImage);
	m_img2 = COPY_RESOURCE("Box", CImage);
	hp = 0;
	m_pos = pos;
	UI_number = UI_Nunber;
};

//デストラクタ
UI::~UI() {

}

//更新処理
void UI::Update() {
	hp = 9 - Player::GetHp();
}

//描画処理
void UI::Draw() {

	m_img.SetPos(GetScreenPos(m_pos));
	//m_img.SetRect();
	m_img.Draw();
}