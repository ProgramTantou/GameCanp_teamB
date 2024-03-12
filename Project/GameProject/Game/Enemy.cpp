
#include "Enemy.h"


TexAnim enemy_Idle[] = {
{0,6},
};

extern TexAnimData enemy_anim_data[] = {
	{enemy_Idle,sizeof(enemy_Idle) / sizeof(enemy_Idle[0])},
};


Enemy::Enemy(const CVector3D& p) : CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f),eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("Enemy", CImage);
	//�Đ��A�j���[�V����
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(0, 0/*???*/);
	m_rect = CRect(-0, 0, 0, 0);
	//���]�t���O
	//m_flip = flip;
}

void Enemy::Update() {
	m_pos;
	//m_pos_old = m_pos;
	//�ړ���
	const float move_spped = 2;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;
	//Base* player = Base::FindObject(eType_Player);
	//���ړ�
	/*if (player->m_pos.x < m_pos.x - 64) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_spped;
		move_flag = true;
	}*/


	m_img.ChangeAnimation(move_dir);
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Enemy::Render() {
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
