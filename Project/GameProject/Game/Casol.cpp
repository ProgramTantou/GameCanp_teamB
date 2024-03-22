#include "Casol.h"
#include "Game.h"

Casol::Casol() : ObjectBase(eType_UI) {
	//画像読み込み
	m_img = COPY_RESOURCE("Cursor", CImage);
	//中心位置設定
	m_img.SetCenter(100, 100);
	//敵存在フラグの初期化
	Enemy_flag_left = false;
	Enemy_flag_right = false;
	//反転用フラグの初期化
	m_flip = false;
	//プレイヤーのポインター
	p = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
}

void Casol::Update() {
	//フラグの初期化
	Enemy_flag_left = false;
	Enemy_flag_right = false;
	//リストの取得
	enemy_list = (TaskManager::FindObjects(eType_Enemy));
	for (auto& v : enemy_list) {
		//プレイヤーの座標の取得
		CVector3D Player_pos = p->GetPos();
		//敵の座標の取得
		e = dynamic_cast<ObjectBase*>(v);
		CVector3D Enemy_pos = e->GetPos();
		if (Player_pos.x > Enemy_pos.x) {
			Enemy_flag_left = true;
		}
		if (Player_pos.x < Enemy_pos.x) {
			Enemy_flag_right = true;
		}
	}
}

void Casol::Render() {
	if (Enemy_flag_left == true) {
		m_flip = true;
		m_img.SetFlipH(m_flip);
		m_img.SetPos(CVector2D(100, 540));
		m_img.Draw();
	}
	if (Enemy_flag_right == true) {
		m_flip = false;
		m_img.SetFlipH(m_flip);
		m_img.SetPos(CVector2D(1800, 540));
		m_img.Draw();
	}
}