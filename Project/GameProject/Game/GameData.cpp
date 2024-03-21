#include "GameData.h"

int GameData::m_score = 0;
int GameData::m_max_score = 0;
int GameData::m_time = 300; //5分
bool GameData::clear_flag = false;
bool GameData::death_flag = false;
int GameData::Stage_number = 1;
int GameData::GetFish1 = 0;
int GameData::GetFish2 = 0;
int GameData::GetFish3 = 0;
int GameData::Enemy_rest = 0;


//コンストラクタ
GameData::GameData() : Task(eType_UI,(int)TaskPrio::UI),
m_fontsize(32),
m_GameData_text("C:\\Windows\\Fonts\\msgothic.ttc", m_fontsize){
	//タイム制御用の変数
	m_count = 0;
	//スコアの初期化
	GameData::m_score = 0;
	//タイムの初期化
	GameData::m_time = 300;
	Score_flag = false;
}

//デストラクタ
GameData::~GameData() {
	
}

//更新処理
void GameData::Update() {
	//1フレーム毎に+1
	m_count++;
	//ゲームクリアでもゲームオーバーでないなら
	if (GameData::clear_flag == false && GameData::death_flag == false) {
		//カウントが60で割り切れるなら
		if (m_count % 60 == 0) {
			//残り時間-1
			m_time -= 1;
			m_count = 0;
		}
	}
	//ゲームクリア時に1度だけタイムスコアを加算
	if (GameData::clear_flag == true) {
		if (Score_flag == false) {
			GameData::m_score += m_time * 10;
			//スコアが最高スコアより高ければ更新
			if (GameData::m_score > GameData::m_max_score) {
				GameData::m_max_score = GameData::m_score;
			}
			Score_flag = true;
		}
	}
	//ゲームオーバー時にスコア比較
	if (GameData::death_flag == true) {
		//スコアが最高スコアより高ければ更新
		if (GameData::m_score > GameData::m_max_score) {
			GameData::m_max_score = GameData::m_score;
		}
	}
}

//描画処理
void GameData::Render() {
	//ゲームクリアでもゲームオーバーでないなら
	if (GameData::clear_flag == false && GameData::death_flag == false) {
		//右上に現在スコアと残りタイムを表示
		m_GameData_text.Draw(1800, 70, 1, 1, 1, "TIME");
		m_GameData_text.Draw(1800, 100, 1, 1, 1, "%d",GameData::m_time);
		m_GameData_text.Draw(1600, 70, 1, 1, 1, "SCORE");
		m_GameData_text.Draw(1600, 100, 1, 1, 1, "%d",GameData::m_score);
		if (GameData::Stage_number <= 3) {
			m_GameData_text.Draw(1328, 70, 1, 1, 1, "残りの敵の数");
			m_GameData_text.Draw(1400, 100, 1, 1, 1, "%d体", GameData::Enemy_rest);
		}
		if (GameData::Stage_number >= 4) {
			m_GameData_text.Draw(1328, 70, 1, 1, 1, "ボスを倒せ！");
		}
	}
	//ゲームクリアかゲームオーバーになったなら
	else if(GameData::clear_flag == true || GameData::death_flag == true) {
		//最終スコアを表示
		//m_GameData_text.Draw(880, 540, 0, 0, 0, "SCORE:%d",GameData::m_score);
	}
}