#include "UI.h"
#include "Player.h"
#include "GameData.h"

//コンストラクタ
UI::UI(const CVector3D& pos, int UI_Nunber) : Task(eType_UI,(int)TaskPrio::UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {

	m_img = COPY_RESOURCE("HP",CImage);
	//m_img2 = COPY_RESOURCE("Box", CImage);
	hp = 0;
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
};

//デストラクタ
UI::~UI() {

}

//更新処理
void UI::Update() {
	hp = Player::m_maxhp - Player::GetHp();
}

//描画処理
void UI::Render() {
	switch (UI_number) {
	case 1:
		m_img.SetPos(200,120);
		m_img.SetRect(hp * 512, 512, (hp + 1) * 512, 1024);
		//ゲームクリアかゲームオーバーでないなら
		if (GameData::clear_flag == false && GameData::death_flag == false) {
			m_img.Draw();
		}
		break;
	case 2:
		//m_img2.SetPos(GetScreenPos(m_pos));
		//m_img2.Draw();
		break;
	}
}