#include "UI.h"
#include "Player.h"

//コンストラクタ
UI::UI() : Base(eType_UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("HP",CImage);
	m_img2 = COPY_RESOURCE("Box", CImage);
	hp = 0;
};

//デストラクタ
UI::~UI() {

}

//更新処理
void UI::Update() {
	//hp = Player::GetHp();
}

//描画処理
void UI::Draw() {

}