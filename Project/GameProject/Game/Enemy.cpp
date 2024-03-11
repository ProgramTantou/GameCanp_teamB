#include "Enemy.h"


TexAnim enemy_Idle[] = {
{0,6},
};

extern TexAnimData enemy_anim_data[] = {
	{enemy_Idle,sizeof(enemy_Idle) / sizeof(enemy_Idle[0])},
};

//�R���X�g���N�^
Enemy::Enemy(const CVector3D& p,int enemy_number,bool flip) :Base(eType_Enemy) {
	Enemy_Number = enemy_number;
	switch (Enemy_Number)
	{
	case 0:
	{
		//�摜����
		m_img = COPY_RESOURCE("Enemy1", CImage);
		//�Đ��A�j���[�V����
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		m_pos = p;
		m_img.SetSize(256, 256);
		//���S�ʒu�ݒ�
		m_img.SetCenter(256 / 2, 256 / 2);
		m_rect = CRect(-256 / 2, -256 / 4, 256 / 2, 256 / 4);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		m_hp = 2;
		bullet_Timer = 0;
		bullet_Interval = 60.0f;
		break;
	}
	case 1:
	{
		//�摜����
		m_img = COPY_RESOURCE("Enemy2", CImage);
		//�Đ��A�j���[�V����
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		m_pos = p;
		m_img.SetSize(256, 256);
		//���S�ʒu�ݒ�
		m_img.SetCenter(256 / 2, 256 / 2);
		m_rect = CRect(-256 / 2, -256 / 4, 256 / 2, 256 / 4);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		m_hp = 3;
		bullet_Timer = 0.0f;
		bullet_Interval = 60.0f;
		break;
	}
	case 2:
	{
		//�摜����
		m_img = COPY_RESOURCE("Enemy3", CImage);
		//�Đ��A�j���[�V����
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		m_pos = p;
		m_img.SetSize(256, 256);
		//���S�ʒu�ݒ�
		m_img.SetCenter(256 / 2, 256 / 2);
		m_rect = CRect(-256 / 2, -256 / 2, 256 / 2, 256 / 2);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		m_hp = 1;
		bullet_Timer = 0.0f;
		bullet_Interval = 60.0f;
		break;
	}

	}
	
}

//�G��HP���擾
int Enemy::GetHP()
{
	return m_hp;
}

void Enemy::Update() {
	m_pos;
	m_pos_old = m_pos;
	//�ړ���
	const float move_speed = 2;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	//���ړ�
	if (player->m_pos.x < m_pos.x - 64) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		m_flip = false;
		move_flag = true;
	}
	//�E�ړ�
	if (player->m_pos.x > m_pos.x + 64) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//���ړ�
	if (player->m_pos.z < m_pos.z ) {
		//�ړ��ʂ�ݒ�
		m_pos.z += -move_speed;
		move_flag = true;
	}
	//��O�ړ�
	if (player->m_pos.z > m_pos.z ) {
		//�ړ��ʂ�ݒ�
		m_pos.z += move_speed;
		//���]�t���O
		move_flag = true;
	}
	
	//��ړ�
	if (player->m_pos.y-70 < m_pos.y ) {
		//�ړ��ʂ�ݒ�
		m_pos.y += -move_speed;
		move_flag = true;
	}
	//���ړ�
	if (player->m_pos.y+70> m_pos.y ) {
		//�ړ��ʂ�ݒ�
		m_pos.y += move_speed;
		//���]�t���O
		move_flag = true;
	}

	//�A�j���[�V�����̕ύX
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
	DrawRect();
}

//�G�̍U��
void Enemy::Attack(CVector2D&)
{
	Base* p = Base::FindObject(eType_Player);
	bullet_Timer++;
	if (bullet_Timer >= bullet_Interval)
	{
		CVector3D bullet_Position = m_pos;
		bullet_Timer = 0.0f;
		//�G�̍U���e�̐���
		//Base::Add(new EnemyBullet(m_pos)
	}
}

//�G�̓����蔻��
void Enemy::Collision(Base* b)
{

}
