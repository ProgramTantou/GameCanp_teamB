#include"Player.h"

//コンストラクタ
Player::Player()
	:CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f))
	, mp_animData(nullptr)
	, mp_image(nullptr)
	
	
{
	m_hp = 200;
	//プレイヤーのアニメーションデータを生成
	int frame = 6;
	mp_animData = new TexAnimData[2]
	{
		//待機アニメ―ション
		{
			new TexAnim[6]
			{
				{0,frame},{1,frame},{2,frame},
				{3,frame},{4,frame},{5,frame},
			},6
		},
		//移動アニメーション
		{
			new TexAnim[6]
			{
				{6,frame},{7,frame},{8,frame},
				{9,frame},{10,frame},{11,frame},

			},6
		},
	};

	//プレイヤー画像の読み込み

	//画像ファイルパス・アニメーションのデータ・1コマの幅(float.x)と高さ(float.y)
	mp_image = CImage::CreateImage("Player.png",mp_animData,384.0f,384.0f);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);

	
}

//デストラクタ
Player::~Player() 
{
	//アニメーションデータの配列を削除
	for (int i = 0; i < 2; i++) {
		delete[]mp_animData[i].pData;
	}
	delete[]mp_animData;
	//画像データを削除
	delete mp_image;
}


//更新処理
void Player::Update()
{
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
	if (HOLD(CInput::eUp)) {
		m_pos.y -= 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	else if (HOLD(CInput::eDown)) {
		m_pos.y += 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	//左右キーどちらも押されていない場合
	if(!isMove)
	{
		//待機アニメーションを再生
		mp_image->ChangeAnimation(0);
	}
	//イメージに座標を設定して、アニメーションを更新
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Player::Death() {
	//基底クラスの死亡処理を呼び出す
	CharaBase::Death();

	//死亡アニメーションを再生
	//再生が終わり次第ゲームオーバー画面を表示
}

//描画処理
void Player::Render()
{
	mp_image->Draw();
}