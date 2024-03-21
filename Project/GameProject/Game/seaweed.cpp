#include "seaweed.h"



seaweed::seaweed(const CVector3D& pos) : ObjectBase(eType_seaweed)
{
	//m_img = COPY_RESOURCE("Seaweed_1", CImage);
	m_img = COPY_RESOURCE("FrontObject", CImage);
	m_img.SetSize(700, 300);
	m_img.SetCenter(700 / 2, 300 / 2);
	m_img.ChangeAnimation(0);

	//���̃I�u�W�F�N�g�͊C����p�ɂȂ����̂ŁA���̃v���O�����͕K�v�Ȃ��Ȃ�܂����B
	/*switch (type)
	{
	case eType_Seaweeds:
		m_img.Load("Image/seaweed.png");
		break;

	case eType_coral:
		m_img.SetSize(40, 40);
		m_img.SetCenter(20, 20);
		m_img.Load("Image/footballfish.png");//�����ڂ��o�O���Ă���B
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
	//�ǒ[�ɓ�����Ə����鏈��
	if (m_pos.x < m_scroll.x - 400)
	{
		Kill();
	}

	if (m_pos.x > m_scroll.x + 400+1920)
	{
		Kill();
	}
}

void seaweed::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}