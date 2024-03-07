#pragma once
#include"CharaBase.h"

class Slime:public CharaBase
{
	//アクセス修飾子
	//自分以外に外部からアクセスし放題
public:
	//自分自身のクラスしかアクセスできない
	//メンバ変数は基本private
	

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="type">スライムの種類</param>
	/// <param name="pos">初期位置</param>
	Slime(int type ,const CVector2D& pos);
	//デストラクタ
	~Slime();


	//更新処理
	void Update()override;
	//描画処理
	void Render()override;
private:
	//自分と自クラスを継承したクラスでアクセスできる
	
	TexAnimData* mp_animData;	//アニメ―ション
	CImage* mp_image;			//画像	
	int m_type;					//スライムの種類





};