#include "Resoult.h"
#include "Title/Title.h"
#include "ObjectBase.h"

Resoult::Resoult() : ObjectBase(eType_Title)
{
	m_img = COPY_RESOURCE("Resoult_kari", CImage);
	m_img.SetSize(1920, 1080);
	m_img.SetCenter(960, 540);
}

Resoult::~Resoult()
{
	//���U���g�Ń{�^���������ƁA�^�C�g���ւƖ߂�B
	new Title();
}

void Resoult::Update()
{
	if (PUSH(CInput::eButton5))
	{
		Kill();
	}
}

void Resoult::Render()
{
	SetPos(m_pos);
	m_img.Draw();
}
