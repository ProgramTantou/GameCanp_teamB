#include "seaweed.h"

static TexAnim seaweed_nomal_anim[] = {
	{0,10},
	{1,10},
	{2,10},
};

TexAnimData seaweedA[] = {
	ANIMDATA(seaweed_nomal_anim),
};

seaweed::seaweed(const CVector3D& pos,int type) : ObjectBase(eType_seaweed)
{
	m_img.Load("Image/seaweed.png");
	m_img.SetSize(800, 800);
	m_img.SetCenter(800 / 2, 800 / 2);
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
}

void seaweed::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}