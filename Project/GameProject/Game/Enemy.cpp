#include "Enemy.h"


TexAnim enemy_Idle[] = {
{0,6},
};

extern TexAnimData enemy_anim_data[] = {
	{enemy_Idle,sizeof(enemy_Idle) / sizeof(enemy_Idle[0])},
};


Enemy::Enemy(const CVector3D& p) :Base(eType_Enemy) {
	//画像複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	//再生アニメーション
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(256, 256);
	m_rect = CRect(-256, -256, 256, 256);
	//反転フラグ
	//m_flip = flip;
}

void Enemy::Update() {
	m_pos;
	m_pos_old = m_pos;
	//移動量
	const float move_speed = 2;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	//const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	//左移動
	if (player->m_pos.x < m_pos.x - 64) {
		//移動量を設定
		m_pos.x += -move_speed;
		move_flag = true;
	}
	//右移動
	if (player->m_pos.x > m_pos.x + 64) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	//奥移動
	if (player->m_pos.z < m_pos.z - 64) {
		//移動量を設定
		m_pos.z += -move_speed;
		move_flag = true;
	}
	//手前移動
	if (player->m_pos.z > m_pos.z + 64) {
		//移動量を設定
		m_pos.z += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	
	//上移動
	if (player->m_pos.y < m_pos.y - 64) {
		//移動量を設定
		m_pos.y += -move_speed;
		move_flag = true;
	}
	//右移動
	if (player->m_pos.y > m_pos.y + 64) {
		//移動量を設定
		m_pos.y += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}


	m_img.ChangeAnimation(move_dir);
	//アニメーション更新
	m_img.UpdateAnimation();
}

void Enemy::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//DrawRect();
}

void Enemy::Collision(Base* b)
{

}