#include "GameData.h"

int GameData::m_score = 0;
int GameData::m_time = 180; //3分
bool GameData::clear_flag = false;
bool GameData::death_flag = false;

//コンストラクタ
GameData::GameData() : Base(eType_UI),
m_fontsize(32),
m_GameData_text("C:\\Windows\\Fonts\\msgothic.ttc", m_fontsize){
	m_count = 0;
}

//更新処理
void GameData::Update() {
	//1フレーム毎に+1
	m_count++;
	//カウントが60で割り切れるなら
	if (m_count % 60 == 0) {
		//残り時間-1
		m_time -= 1;
		m_count = 0;
	}
	//ゲームクリアかゲームオーバーになったなら
	if (GameData::clear_flag == true || GameData::death_flag == true) {
		//フォントサイズ4倍
		m_fontsize *= 4;
	}
	//ゲームをクリアしたなら
	if (GameData::clear_flag == true) {
		//スコアに残りタイムを加算
		GameData::m_score += m_time * 10;
	}
}

//描画処理
void GameData::Draw() {
	//ゲームクリアかゲームオーバーでないなら
	if (GameData::clear_flag == false || GameData::death_flag == false) {
		//右上に現在スコアと残りタイムを表示
		m_GameData_text.Draw(750, 90, 0, 0, 0, "TIME");
		m_GameData_text.Draw(750, 120, 0, 0, 0, "%d",GameData::m_time);
		m_GameData_text.Draw(650, 90, 0, 0, 0, "SCORE");
		m_GameData_text.Draw(650, 120, 0, 0, 0, "%d",GameData::m_score);
	}
	//ゲームクリアかゲームオーバーになったなら
	else {
		//最終スコアを表示
		m_GameData_text.Draw(960, 540, 0, 0, 0, "%d",GameData::m_score);
	}
}