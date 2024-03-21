#include "FrontObject.h"

FrontObject::FrontObject(int type) : Task(eType_Front,(int)TaskPrio::UI)
{
	m_img = COPY_RESOURCE("FrontObject", CImage);
	m_img.SetSize(400, 400);
	m_img.SetCenter(200, 200);
	front_type = type;
	//m_img.Load()
	/*switch (front_type)
	{
	case eType_Seaweeds:
		m_img.Load("Image/footballfish.png");
		break;

	case eType_coral:
		m_img.SetSize(40, 40);
		m_img.SetCenter(20, 20);
		m_img.Load("Image/footballfish.png");
		break;

	case eType_jellyfish:
		m_img.Load("Image/jellyfish.png");
		break;

	default:
		m_img.Load("Image/footballfish.png");
		break;
	}*/
	m_img.Load("Image/jellyfish.png");
	m_img.SetSize(2000, 2000);
	m_img.SetCenter(1000, 1000);
}

void FrontObject::Update()
{
	
}

void FrontObject::Render()
{
	float sc;
	m_img.SetPos(1920/2,1080);
	sc = ObjectBase::m_scroll.x*2;
	m_img.SetRect(sc, 0, sc + 1920, 1080+130);
	m_img.Draw();
}
