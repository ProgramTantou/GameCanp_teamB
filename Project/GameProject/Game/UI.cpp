#include "UI.h"
#include "Player.h"
#include "GameData.h"

//コンストラクタ
UI::UI(const CVector3D& pos, int UI_Nunber) : Task(eType_UI,(int)TaskPrio::UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 32) {
	hp = 0;
	UI_number = UI_Nunber;
	switch (UI_number) {
	case 1:
		m_img = COPY_RESOURCE("HP", CImage);
		break;
	case 2:
		m_img2 = COPY_RESOURCE("Box", CImage);
		m_img_fish1 = COPY_RESOURCE("Fish1_UI", CImage);
		m_img_fish2 = COPY_RESOURCE("Fish2_UI", CImage);
		m_img_fish3 = COPY_RESOURCE("Fish3_UI", CImage);
		break;
	}
	switch (UI_number)
	{
	case 1:
		m_img.SetCenter(128, 128);
		m_img.SetSize(256, 256);
		break;
	case 2:
		m_img2.SetCenter(128, 128);
		m_img2.SetSize(256, 256);
		m_img_fish1.SetCenter(96, 96);
		m_img_fish1.SetSize(192, 192);
		m_img_fish2.SetCenter(96, 96);
		m_img_fish2.SetSize(192, 192);
		m_img_fish3.SetCenter(96, 96);
		m_img_fish3.SetSize(192, 192);
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
		m_img.SetPos(170,130);
		m_img.SetRect(hp * 512, 512, (hp + 1) * 512, 1024);
		//ゲームクリアかゲームオーバーでないなら
		if (GameData::clear_flag == false && GameData::death_flag == false) {
			m_img.Draw();
		}
		break;
	case 2:
		//ゲームクリアかゲームオーバーでないなら
		if (GameData::clear_flag == false && GameData::death_flag == false) {
			for (int i = 1; i <= 3; i++) {
				m_img2.SetPos(170 + 188 * i, 140);
				m_img2.Draw();
			}
			m_img_fish1.SetPos(170 + 188 * 1, 140);
			m_img_fish1.SetRect(0, 0, 512, 512);
			m_img_fish1.Draw();
			m_UI_text.Draw(199 + 190 * 1, 200, 1, 1, 1, "×%d",GameData::GetFish1);
			m_img_fish2.SetPos(170 + 188 * 2, 140);
			m_img_fish2.Draw();
			m_UI_text.Draw(198 + 190 * 2, 200, 1, 1, 1, "×%d", GameData::GetFish2);
			m_img_fish3.SetPos(170 + 188 * 3, 140);
			m_img_fish3.SetRect(0, 0, 512, 512);
			m_img_fish3.Draw();
			m_UI_text.Draw(197 + 190 * 3, 200, 1, 1, 1, "×%d", GameData::GetFish3);
		}
		break;
	}
}