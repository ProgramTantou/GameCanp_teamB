#include "Title.h"

Title::Title(const CVector2D& p) :Base(eType_Screen) {
	m_img.Load("Image/�^�C�g�����.png");
	m_rad = 15;
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_pos = p;

	//�ϐ��ꗗ
	int select_mode = 1;//���ݑI�𒆂̃��[�h

}

void Title::Update() {
	//���[�h�I������
	if (select_mode < 4)
	{
		if (PUSH(CInput::eUp))
		{
			select_mode += 1;
		}
		if (select_mode >= 4)
		{
			select_mode = 1;
		}
	}
}

void Title::Draw() {
	m_img.SetPos((m_pos));
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}