#include "Player.h"

//コンストラクタ
Player::Player() {
	m_pos = CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f);

	//プレイヤーのアニメーションデータを生成
	int flame = 6;
	mp_animData = new TexAnimData[2]
	{
		//待機アニメーション
		{
			new TexAnim[6]{
				{0,flame},{1,flame},{2,flame},
				{3,flame},{4,flame},{5,flame},
			},
			6
		},
		//移動アニメーション
		{
			new TexAnim[6]{
				{6,flame},{7,flame},{8,flame},
				{9,flame},{10,flame},{11,flame},
			},
			6
		},
	};

	//プレイヤーの画像を読み込み
	mp_image = CImage::CreateImage("player.png");
}

//デストラクタ
Player::~Player() {

}

//プレイヤーの座標を取得
CVector2D Player::GetPos()
{
	return m_pos;
}

//プレイヤーの座標を設定
void Player::SetPos(CVector2D pos) {
	m_pos = pos;
}