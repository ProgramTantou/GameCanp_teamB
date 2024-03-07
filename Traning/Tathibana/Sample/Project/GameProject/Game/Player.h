#pragma once
#include"CharaBase.h"
class Player :public CharaBase 
{
	//アクセス修飾子
	//自分以外に外部からアクセスし放題
public:
	//自分自身のクラスしかアクセスできない
	//メンバ変数は基本private
	
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
	//死亡処理
	void Death() override;
	
	//継承元ObjectBase・継承先Player
	//宣言部・・継承元virtual（前）・継承先override(後ろ）
	
	//更新処理
	void Update() override;
	//描画処理
	void Render();
private:
	//自分と自クラスを継承したクラスでアクセスできる
	
	TexAnimData* mp_animData;	//プレイヤーのアニメ―ション
	CImage* mp_image;			//プレイヤーの画像
					
protected:
};