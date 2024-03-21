#include "FrontObject.h"

static TexAnim seaweed_nomal_anim[] = {
	{0,10},
	{1,10},
	{2,10},
};

TexAnimData seaweedA[] = {
	ANIMDATA(seaweed_nomal_anim),
};

FrontObject::FrontObject(int type) : Task(eType_Front,(int)TaskPrio::UI)
{
	//m_img.Load("Image/Seaweed_1.png", seaweedA, 512, 500);
	m_img = COPY_RESOURCE("Seaweed_1", CImage);
	m_img.ChangeAnimation(0);
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
	m_img.SetSize(1000, 1000);
	m_img.SetCenter(500, 500);
	
}

void FrontObject::Update()
{
	m_img.UpdateAnimation();
}

void FrontObject::SetPos(const CVector2D& pos)
{
	m_pos = pos;
}

void FrontObject::Render()
{
	m_img.SetPos(1920 / 2, 1380);
	float sc;
	//m_img.SetPos(1920/2,1200);
	sc = ObjectBase::m_scroll.x*1.5;
	m_img.SetRect(sc, 0, sc + 1920*10/4, 1080/2);
	m_img.Draw();
}
