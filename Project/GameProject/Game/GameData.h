#pragma once
#include "Task.h"

class GameData : public Task {
public:
	static int m_score; //最終スコア
	static int m_time;  //残り時間
	static int m_max_score; //最高スコア
	static bool clear_flag; //ゲームクリア確認用のフラグ
	static bool death_flag; //ゲームオーバー確認用のフラグ
	//コンストラクタ
	GameData();
	//デストラクタ
	~GameData();
private:
	int m_count;        //時間計算用の変数
	int m_fontsize;     //文字大きさのサイズ
	CFont m_GameData_text;  //文字表示オブジェクト
	//更新処理
	void Update() override;
	//描画処理
	void Render() override;
};
