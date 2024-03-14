#include "GameOver.h"
#include"Game.h"
#include"Casol.h"
#include"Player.h"
#include"Enemy.h"
#include"Field.h"
#include"UI.h"
#include"GameData.h"
#include "TaskManager.h"
#include "../Title/Title.h"

GameOver::GameOver(const CVector2D& p) : ObjectBase(eType_Title) {
	m_img.Load("Image/gameover.png");
	m_img.SetSize(2000, 1200);
	m_img.SetCenter(1000, 600);
	new Casol(CVector2D(950, 600));
	select_mode = 1;
}

void GameOver::Update() {
	//�Q�[���I�[�o�[���̑���
	//���g���C
	

	//�^�C�g���֖߂�
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

	//�P�ŃQ�[�����g���C
//�Q�Ń^�C�g���ɖ߂�
//�R�ŃC�O�W�b�g
	switch (select_mode)
	{
	case 1://���g���C
		if (PUSH(CInput::eButton5))
		{
			new Game();
			Kill();
		}
	break;

	case 2://�^�C�g���ɖ߂�
		if (PUSH(CInput::eButton5))
		{
			Kill();
			new Title();
			new UI(CVector2D(10, 120), 1);
		}
		break;

	default:
		break;
	}
}

void GameOver::Render() {
	
	m_img.SetPos(950,500);
	m_img.Draw();
}