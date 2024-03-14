#include "Resoult.h"

Resoult::Resoult() : Task(eType_Title,(int)TaskPrio::UI)
{
	m_img = COPY_RESOURCE("Resoult", CImage);
	m_img.SetSize(1920, 1080);
	m_img.SetCenter(960, 540);
}

Resoult::~Resoult()
{
}

void Resoult::Update()
{

}

void Resoult::Render()
{
}
