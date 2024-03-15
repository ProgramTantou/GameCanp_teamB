#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"

Title::Title() : ObjectBase(eType_Title) {
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	new Casol(CVector2D(950, 600));
	//�ϐ��ꗗ
	int select_mode = 1;//���ݑI�𒆂̃��[�h
}

Title::~Title()
{
	new Game();
}

void Title::Update() {
	
	//�X�y�[�X�L�[�łf�`�l�d�𐶐����A�Q�[���X�^�[�g����B
		if (PUSH(CInput::eButton5) )
		{
			Kill();
		}
}

void Title::Render() {
	m_img.SetPos(900,500);
	m_img.Draw();
}
