#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	//HPの画像データ
	CImage m_img;
	//所持している魚の画像データ
	CImage m_img2;
	//スコア表示用の文字表示オブジェクト
	CFont m_UI_text;
	//画像矩形用の変数
	int hp;
	//UIの判別用の変数
	int UI_number;
	//プレイヤーのポインター
	Base* p_player;
public:
	//コンストラクタ
	UI(const CVector3D& pos,int UI_Nunber, Base* b);
	//デストラクタ
	~UI();
	//更新処理
	void Update();
	//描画処理
	void Draw();
};