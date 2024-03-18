#pragma once
#include "Task.h"

class Fade : public Task {
private:
	//画像データ
	CImage m_img;
	//経過時間の変数
	int time;
	//アルファ値の変数
	float Arufa;
	//アルファ値制御用のフラグ
	bool Arufa_flag;
public:
	//コンストラクタ
	Fade();
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;
};
