#include "GameData.h"

int GameData::m_score = 0;
int GameData::m_time = 180; //3分
bool GameData::clear_flag = false;
bool GameData::death_flag = false;

//コンストラクタ
GameData::GameData() : Task(eType_UI,(int)TaskPrio::UI),
m_fontsize(32),
m_GameData_text("C:\\Windows\\Fonts\\msgothic.ttc", m_fontsize){
	m_count = 0;
	GameData::m_score = 0;
	GameData::m_time = 180;
}

//デストラクタ
GameData::~GameData() {
	//ゲームをクリアしたなら
	if (GameData::clear_flag == true) {
		//スコアに残りタイムを加算
		GameData::m_score += m_time * 10;
	}
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
	//ゲームクリアかゲームオーバーになったなら
	if (GameData::clear_flag == true || GameData::death_flag == true) {
		//フォントサイズ4倍
		m_fontsize *= 4;
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
	}
	//ゲームクリアかゲームオーバーになったなら
	else if(GameData::clear_flag == true || GameData::death_flag == true) {
		//最終スコアを表示
		m_GameData_text.Draw(880, 540, 0, 0, 0, "SCORE:%d",GameData::m_score);
	}
}