#include "Player.h"

//コンストラクタ
Player::Player()
	:CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f))
	
{
	m_hp = 200;

	//プレイヤーのアニメーションデータを生成
	int frame = 6;
	mp_animData = new TexAnimData[2]
	{
		{
			//待機アニメーション
		new TexAnim[6]
			{
				{0,frame},{1,frame},{2,frame},
				{3,frame},{4,frame},{5,frame},
			},
			6
		},
		{
			//移動アニメーション
			new TexAnim[6]
				{
					{6,frame},{7,frame},{8,frame},
					{9,frame},{10,frame},{11,frame},
				},
				6
			},
	},
		//プレイヤーの画像の読み込み
		mp_image = CImage::CreateImage
		(
			"player.png",		//画像ファイルのパス
			mp_animData,		//アニメーションのデータ
			384.0f, 384.0f		//1コマの幅と高さ
		);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);
};

//デストラクタ
Player::~Player()
{
	//アニメーションデータの配列を削除
	for (int i = 0; i < 2; i++)
	{
		delete[] mp_animData[i].pData;
	}
	delete[] mp_animData;

	//画像データを削除
	delete[] mp_image;
}

/*
//Get　<- ゲッター
//プレイヤーの座標を取得
const CVector2D& Player::GetPos() const
{
	return m_pos;
}

//Set  <- セッター
//プレイヤーの座標を設定
void Player::SetPos(const CVector2D& pos)
{
	m_pos = pos;
}
*/

//死亡したときの処理
void Player::Death()
{
	//基底クラスの死亡処理も呼び出す。
	CharaBase::Death();

	//死亡アニメーションを再生して、
	//死亡アニメーションが終わったら、
	//ゲームオーバー画面を表示する。
}

//更新処理
void Player::Update() {
	bool isMove = false;
	//左キーを押している間
	if (HOLD(CInput::eLeft))
	{	
		//左方向へ移動
		m_pos.x -= 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
		isMove = true;
	}
	//右キーを押している間
	else if (HOLD(CInput::eRight))
	{	
		//右方向へ移動
		m_pos.x += 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(false);
		isMove = true;
	}
	if (HOLD(CInput::eUp))
	{
		//if (m_pos.y == 330) 
		//{
		//		m_pos.y -= 0.0f;
		//}
		
		 m_pos.y -= 5.0f;
		
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	else if (HOLD(CInput::eDown))
	{

		//if (m_pos.y == 650)
		//{
		//	m_pos.y -= 0.0f;
		//}

		m_pos.y += 5.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	
	//左右どちらのキーも押されていない場合
	if (!isMove)
	{	//待機アニメーションを再生
		mp_image->ChangeAnimation(0);
		
	}


	{	//イメージに座標を設定して、アニメーションを更新
		mp_image->SetPos(m_pos);
		mp_image->UpdateAnimation();
	}
}

//描画処理
void Player::Render()
{
	mp_image->Draw();

}
