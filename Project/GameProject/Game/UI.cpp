#include "UI.h"
#include "Player.h"

//�R���X�g���N�^
UI::UI() : Base(eType_UI),
m_UI_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("HP",CImage);
	m_img2 = COPY_RESOURCE("Box", CImage);
	hp = 0;
};

//�f�X�g���N�^
UI::~UI() {

}

//�X�V����
void UI::Update() {
	//hp = Player::GetHp();
}

//�`�揈��
void UI::Draw() {

}