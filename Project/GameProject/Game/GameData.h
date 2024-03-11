#pragma once
#include "../Base/Base.h"

class GameData : public Base {
public:
	static int m_score; //最終スコア
	static int m_time;  //残り時間
	static bool clear_flag; //ゲームクリア確認用のフラグ
	static bool death_flag; //ゲームオーバー確認用のフラグ
	//コンストラクタ
	GameData();
private:
	int m_count;        //時間計算用の変数
	int m_fontsize;     //文字大きさのサイズ
	CFont m_GameData_text;  //文字表示オブジェクト
	//更新処理
	void Update();
	//描画処理
	void Draw();
};
