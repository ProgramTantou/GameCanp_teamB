#include "Slime.h"

/*const CVector2D& Slime::GetPos()
{
	return m_pos;
}

void Slime::SetPos(CVector2D pos)
{
	m_pos = pos;
}*/

//コンストラクタ
Slime::Slime(int type,const CVector2D& pos)
	:m_pos(pos)
	,mp_anim(nullptr)
	,mp_image(nullptr)
	,m_hp(100)
	,m_type(type)
	{
	int freme = 6;

	mp_anim = new TexAnimData[1]
	{
		{
			new TexAnim[4]
			{
				{ 0, freme}, { 1, freme}, { 2, freme}, { 3, freme},
			},
			4
		},
	};

	std::string imagePath;
	if (m_type == 0) imagePath = "slime_a.png";
	else if (m_type == 1) imagePath = "slime_b.png";
	else if (m_type == 2) imagePath = "slime_c.png";
	//プレイヤーの画像を読み込み
	mp_image = CImage::CreateImage
	(
		imagePath.c_str(),
		mp_anim,
		256.0f, 256.0f
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(128.0f, 184.0f);
	mp_image->SetFlipH(true);
}

//デストラクタ
Slime::~Slime()
{

}

void Slime::Update()
{
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Slime::Render()
{
	mp_image->Draw();
}
