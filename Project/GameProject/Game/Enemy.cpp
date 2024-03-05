#include "Enemy.h"

Enemy::Enemy(const CVector2D& p, bool flip) :Base(eType_Enemy) {
	//画像複製
	//m_img = COPY_RESOURCE("Enemy.png", CImage);
	//再生アニメーション
	//m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(0, 0/*???*/);
	m_rect = CRect(-0, 0, 0, 0);
	//反転フラグ
	m_flip = flip;
}

void Enemy::Update() {
	m_pos;
	m_pos_old = m_pos;



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