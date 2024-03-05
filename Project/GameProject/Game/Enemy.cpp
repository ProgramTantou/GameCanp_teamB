#include "Enemy.h"

Enemy::Enemy(const CVector2D& p, bool flip) :Base(eType_Enemy) {
	//�摜����
	//m_img = COPY_RESOURCE("Enemy.png", CImage);
	//�Đ��A�j���[�V����
	//m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(0, 0/*???*/);
	m_rect = CRect(-0, 0, 0, 0);
	//���]�t���O
	m_flip = flip;
}

void Enemy::Update() {
	m_pos;
	m_pos_old = m_pos;



	m_img.ChangeAnimation(move_dir);
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Enemy::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//DrawRect();
}

void Enemy::Collision(Base* b)
{

}