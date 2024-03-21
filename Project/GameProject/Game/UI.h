#pragma once
#include "Task.h"

class UI : public Task {
private:
	//HPの画像データ
	CImage m_img;
	//所持している魚の画像データ
	CImage m_img2;
	//魚の画像データ
	CImage m_img_fish1;
	CImage m_img_fish2;
	CImage m_img_fish3;
	//スコア表示用の文字表示オブジェクト
	CFont m_UI_text;
	//画像矩形用の変数
	int hp;
	//UIの判別用の変数
	int UI_number;
	//プレイヤーのポインター
	Task* p_player;
public:
	//コンストラクタ
	UI(const CVector3D& pos,int UI_Nunber);
	//デストラクタ
	~UI();
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;
};