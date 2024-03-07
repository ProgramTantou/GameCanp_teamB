#pragma once
#include "ObjectBase.h"
#include "CharaBase.h"

class Player : public CharaBase
{

	//自分自身の外部からアクセス可能
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//死亡したときの処理

	void Update() override;

	void Death() override;

	void Render() override;
	/// <summary>
	/// プレイヤーの座標を決定
	/// </summary>
	
	//アクセス修飾子
	//自分自身のクラスしかアクセスできない。
private:
	TexAnimData* mp_anim;
	CImage* mp_image;//プレイヤーの画像
	//自分と自クラスを継承したクラスからアクセス可能
};