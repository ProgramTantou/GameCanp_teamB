#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"

Title::Title() : ObjectBase(eType_Title) {
	//m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_img.Load("Image/title.png");
	new Casol(CVector2D(1000, 600));
	m_img.ChangeAnimation(1, false);
	//�ϐ��ꗗ
	int select_mode = 1;//���ݑI�𒆂̃��[�h
}

Title::~Title()
{
	new Game();
}

void Title::Update() {
	
	//�X�y�[�X�L�[�łf�`�l�d�𐶐����A�Q�[���X�^�[�g����B
	if (PUSH(CInput::eRight))
	{
		select_mode += 1;
	}

	if (select_mode > 2)
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
			select_mode = 2;
		}
	}

	if(select_mode!=2)
	{
		m_img.Load("Image/title.png");
	}

	//�P�ŃQ�[���X�^�[�g
//�Q�ŃN���W�b�g
//�R�ŃC�O�W�b�g
	switch (select_mode)
	{
	case 1:
		if (PUSH(CInput::eButton5))
		{
			Kill();
		}
		break;

	case 2:
		if (PUSH(CInput::eButton5))
		{
			m_img.Load("Image/control_manual.png");
		}
		break;

	default:
		break;
	}
}

void Title::Render() {
	m_img.SetPos(1000, 600);
	m_img.Draw();
}
