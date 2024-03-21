#include "seaweed.h"



seaweed::seaweed(const CVector3D& pos,int type) : ObjectBase(eType_seaweed)
{
	//m_img = COPY_RESOURCE("Seaweed_1", CImage);
	m_img = COPY_RESOURCE("FrontObject", CImage);
	m_img.SetSize(600, 300);
	m_img.SetCenter(700 / 2, 300 / 2);
	m_img.ChangeAnimation(0);

	//このオブジェクトは海草専用になったので、このプログラムは必要なくなりました。
	/*switch (type)
	{
	case eType_Seaweeds:
		m_img.Load("Image/seaweed.png");
		break;

	case eType_coral:
		m_img.SetSize(40, 40);
		m_img.SetCenter(20, 20);
		m_img.Load("Image/footballfish.png");//見た目がバグっている。
		break;

	case eType_jellyfish:
		m_img.Load("Image/jellyfish.png");
		break;

	default:
		break;
	}*/
	
	m_pos=pos;
}

void seaweed::Update()
{
	//シーウィードもランダムで登場するようにする？敵と同じように？
	m_img.UpdateAnimation();
}

void seaweed::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}