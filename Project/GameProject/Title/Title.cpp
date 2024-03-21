#include "Title.h"
#include "Game/Casol.h"
#include "../Game/TaskManager.h"
#include "../Game/ObjectBase.h"
#include "Game/Game.h"
#include "Game/Resoult.h"
#include "Game/seaweed.h"
#include "Game/FrontObject.h"
#include "Game/jellyfish_Manager.h"

Title::Title() : ObjectBase(eType_Title) {
	//m_img = COPY_RESOURCE("Title", CImage);
	m_pos.x = 600;
	m_pos.y = 1000;
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	m_img.Load("Image/title.png");
	//new Casol(CVector2D(1000, 600));
	//�ϐ��ꗗ
	select_mode = 1;//���ݑI�𒆂̃��[�h
	selectOK = true;
	cnt = 0;
}

Title::~Title()
{
	new Game();//���U���g�e�X�g�v���C�p�ɁA�ꎞ�I�Ƀ^�C�g���J�n���Ƀ��U���g���o��悤�ɂ��܂��B
	new seaweed(CVector3D(500, 700, 0));
	new seaweed(CVector3D(500, 700, 0));
	new seaweed(CVector3D(500, 700, 0));
	new FrontObject(eType_coral);
	new jellyfish_Manager();
	//new Resoult(2);

}

void Title::Update() {

	if (PUSH(CInput::eButton2))
	{
		Kill();
	}

	if (PUSH(CInput::eButton3))
	{
		m_img.Load("Image/control_manual.png");
	}

	/*
	//cnt��������
	if (cnt > 0)
	{
		cnt--;
	}

	//�Z���N�g���[�h���Q�̎��ɃX�y�[�X�L�[�łf�`�l�d�𐶐����A�Q�[���X�^�[�g����B
	if (selectOK)
	{
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
		if (PUSH(CInput::eButton5) && cnt==0 && selectOK)
		{
			selectOK = false;
			cnt = 30;
			m_img.Load("Image/control_manual.png");
		}
		break;

	default:
		break;
	}

	//�Z���N�g���[�h���Q�̎��́A�X�y�[�X�L�[�������΍ĂуZ���N�g�ł���B
		if (PUSH(CInput::eButton5) && selectOK==false && cnt==0)
		{
			selectOK = true;
			cnt = 30;
			m_img.Load("Image/title.png");
			//select_mode = 1;
		}
		*/
}

void Title::Render() {
	m_img.SetPos(1000, 600);
	m_img.Draw();
}