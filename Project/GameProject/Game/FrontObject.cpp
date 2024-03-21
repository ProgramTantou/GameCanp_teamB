#include "FrontObject.h"

FrontObject::FrontObject() : Task(eType_UI, (int)TaskPrio::FrontObjects)
{
	m_img.Load()
}

void FrontObject::Update()
{
}

void FrontObject::Render()
{
}
