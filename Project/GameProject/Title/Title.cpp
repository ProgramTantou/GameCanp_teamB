#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"

Title::Title() : ObjectBase(eType_Title) {
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.Load("Image/title.png");
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	new Casol(CVector2D(950, 600));
	//�ϐ��ꗗ
	int select_mode = 1;//���ݑI�𒆂̃��[�h
}

void Title::Update() {
	//���[�h�I������
	if (PUSH(CInput::eRight))
	{
		select_mode += 1;
	}

	if (select_mode > 3)
	{
		if (PUSH(CInput::eRight))
		{
			select_mode = 1;
		}
	}

	if (PUSH(CInput::eLeft))
	{
		select_mode -= 1;
	}
	if (select_mode < 1)
	{
		if (PUSH(CInput::eLeft))
		{
			select_mode = 3;
		}
	}

	//�P�ŃQ�[���X�^�[�g
//�Q�ŃN���W�b�g
//�R�ŃC�O�W�b�g
		if (PUSH(CInput::eButton5))
		{
			Kill();
		}
}

void Title::Render() {
	m_img.SetPos(900,500);
	m_img.Draw();
}
