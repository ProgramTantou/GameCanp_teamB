#include "Player.h"

//コンストラクタ
Player::Player()
	: CharaBase(CVector2D(SCREEN_WIDTH*0.5f,SCREEN_HEIGHT*0.75f))
	,mp_anim(nullptr)
	,mp_image(nullptr)
{
	m_hp = 200;

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

void Player::Death()
{
	//基底クラスの死亡処理も呼び出す。
	CharaBase::Death();

	//死亡アニメーション
	//死亡アニメーションが終わったら
	//ゲームオーバー画面を表示する
}

void Player::Update()
{
	//左キーを押している間
	if (HOLD(CInput::eLeft))
	{
		//左方向へ移動
		m_pos.x -= 4.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
	}
	else if (HOLD(CInput::eRight))
	{
		//右方向へ移動
		m_pos.x += 4.0f;
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
		m_pos.y -= 4.0f;
		mp_image->ChangeAnimation(1);
	}
	else if (HOLD(CInput::eDown))
	{
		//右方向へ移動
		m_pos.y += 4.0f;
		mp_image->ChangeAnimation(1);
	}


	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Player::Render()
{
	mp_image->Draw();
}
