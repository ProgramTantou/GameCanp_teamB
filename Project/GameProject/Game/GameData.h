#pragma once
#include "Task.h"

class GameData : public Task {
public:
	static int m_score; //最終スコア
	static int m_time;  //残り時間
	static int m_max_score; //最高スコア
	static bool clear_flag; //ゲームクリア確認用のフラグ
	static bool death_flag; //ゲームオーバー確認用のフラグ
	static int Stage_number; //ステージ変更用変数
	static int GetFish1; //1種類目の魚の入手数
	static int GetFish2; //2種類目の魚の入手数
	static int GetFish3; //3種類目の魚の入手数
	static int Enemy_rest; //敵の残りの数
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
	bool Score_flag; //スコア加算制御用フラグ
};
