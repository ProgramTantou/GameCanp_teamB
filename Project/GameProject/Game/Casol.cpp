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
	//敵のポインター
	e = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Enemy));
	
}

void Casol::Update() {
	//プレイヤーの座標の取得
	CVector3D Player_pos = p->GetPos();
	//プレイヤーの座標の取得
	CVector3D Enemy_pos = e->GetPos();
	if (e == nullptr) {
		e = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Enemy));
	}
	if (Player_pos.x > Enemy_pos.x) {
		Enemy_flag_left = true;
	}
	else {
		Enemy_flag_left = false;
	}
	if (Player_pos.x < Enemy_pos.x) {
		Enemy_flag_right = true;
	}
	else {
		Enemy_flag_right = false;
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