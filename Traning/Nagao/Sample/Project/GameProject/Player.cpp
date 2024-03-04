#include "Player.h"

const CVector2D& Player::GetPos()
{
	return m_pos;
}

void Player::SetPos(CVector2D& pos)
{
	m_pos = pos;
}

//コンストラクタ
Player::Player()
{
	m_pos = CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f);

	int freme = 6;
	
	mp_anim = new TexAnimData[2]
	{
		{
		new TexAnim[6]
		{
			{0,freme},{1,freme},{2,freme},
			{3,freme},{4,freme},{5,freme},
		},
		6
		},

		{
			new TexAnim[6]
		{
			{6,freme},{7,freme},{8,freme},
			{9,freme},{10,freme},{11,freme},
		},
		6
		},
	};
	//プレイヤーの画像を読み込み
	mp_image = CImage::CreateImage
	(
		"player.png",
		mp_anim,
		384.0f, 384.0f
	);
	mp_image->SetCenter(192.0f, 328.0f);
}

//デストラクタ
Player::~Player()
{

}

void Player::Update()
{
	//左キーを押している間
	if (HOLD(CInput::eLeft))
	{
		//左方向へ移動
		m_pos.x -= 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
	}
	else if (HOLD(CInput::eRight))
	{
		//右方向へ移動
		m_pos.x += 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(false);
	}
	else
	{
		mp_image->ChangeAnimation(0);
	}

	if (HOLD(CInput::eUp))
	{
		//左方向へ移動
		m_pos.y -= 8.0f;
		mp_image->ChangeAnimation(1);
	}
	else if (HOLD(CInput::eDown))
	{
		//右方向へ移動
		m_pos.y += 8.0f;
		mp_image->ChangeAnimation(1);
	}


	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Player::Render()
{
	mp_image->Draw();
}
