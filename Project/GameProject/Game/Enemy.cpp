#include "Enemy.h"
#include "EnemyAttack.h"
#include "TaskManager.h"
#include "Fish.h"
#include "GameData.h"

TexAnim enemy_Idle[] = {
{0,6},
};

extern TexAnimData enemy_anim_data[] = {
	{enemy_Idle,sizeof(enemy_Idle) / sizeof(enemy_Idle[0])},
};

//�R���X�g���N�^
Enemy::Enemy(const CVector3D& p,int enemy_number,bool flip) :ObjectBase(eType_Enemy) {
	Enemy_Number = enemy_number;
	//�ړ���
	  move_speed = 2;
	  move_speed1 = 1;
	  move_speedtossin = 4;
	  timer = 0;
	  m_damage_no = rand();
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
		m_rect = CRect3D(-256 / 2,-256 / 4,256 / 2,256 / 4, 256 / 2,-256 / 2);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		
		m_hp = 2;
		attack_Timer = 0.0f;
		attack_Interval = 120.0f;
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
		m_rect = CRect3D(-256 / 2 , -256 / 4, 256 / 2, 256 / 4,256 , -256 );
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		
		m_hp = 3;
		attack_Timer = 0.0f;
		attack_Interval = 150.0f;
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
		m_rect = CRect3D(-256 / 2, -256 / 2, 256 / 2, 256 / 2, 256 / 2, -256 / 2);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();

		m_hp = 1;
		attack_Timer = 0.0f;
		attack_Interval = 120.0f;
		break;
	}

	}
	//�U���ԍ�
	attack_no = rand();
}

//�G��HP���擾
int Enemy::GetHP()
{
	return m_hp;
}

void Enemy::GiveScore(int Score)
{
	GameData::m_score + (Score);
}

void Enemy::Update() {
	m_pos;
	//m_pos_old = m_pos;
	
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));
	switch (Enemy_Number)
	{
	case 0:
	{if (player) {
		//���ړ�
if (player->m_pos.x < m_pos.x - 64) {
	//�ړ��ʂ�ݒ�
	m_pos.x += -move_speed1;
	m_flip = false;
	move_flag = true;
	Attack();
}
//�E�ړ�
if (player->m_pos.x > m_pos.x + 64) {
	//�ړ��ʂ�ݒ�
	m_pos.x += move_speed1;
	//���]�t���O
	m_flip = true;
	move_flag = true;
	Attack();
	
}
//���ړ�
if (player->m_pos.z < m_pos.z) {
	//�ړ��ʂ�ݒ�
	m_pos.z += -move_speed1;
	move_flag = true;
	
}
//��O�ړ�
if (player->m_pos.z > m_pos.z) {
	//�ړ��ʂ�ݒ�
	m_pos.z += move_speed1;
	//���]�t���O
	move_flag = true;
	
}

//��ړ�
if (player->m_pos.y - 70 < m_pos.y) {
	//�ړ��ʂ�ݒ�
	m_pos.y += -move_speed1;
	move_flag = true;
}
//���ړ�
if (player->m_pos.y + 70 > m_pos.y) {
	//�ړ��ʂ�ݒ�
	m_pos.y += move_speed1;
	//���]�t���O
	move_flag = true;
}

	}
	break;
	}
	case 1:

	{if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x - 64) {
			//�ړ��ʂ�ݒ�
			m_pos.x -= move_speed;
			m_flip = false;
			move_flag = true;
			Attack();

		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x + 64) {
			//�ړ��ʂ�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
			Attack();

		}
		//���ړ�
		if (player->m_pos.z < m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += -move_speed;
			move_flag = true;

		}
		//��O�ړ�
		if (player->m_pos.z > m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += move_speed;
			//���]�t���O
			move_flag = true;
		}

		//��ړ�
		if (player->m_pos.y < m_pos.y) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -move_speed;
			move_flag = true;
		}
		//���ړ�
		if (player->m_pos.y > m_pos.y) {
			//�ړ��ʂ�ݒ�
			m_pos.y += move_speed;
			//���]�t���O
			move_flag = true;
		}
		

	}
		break;
	}
	case 2:
	{if (player) {
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
		if (player->m_pos.z < m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += -move_speed;
			move_flag = true;
		}
		//��O�ړ�
		if (player->m_pos.z > m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += move_speed;
			//���]�t���O
			move_flag = true;
		}

		//��ړ�
		if (player->m_pos.y - 120 < m_pos.y) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -move_speed;
			move_flag = true;
		}
		//���ړ�
		if (player->m_pos.y > m_pos.y) {
			//�ړ��ʂ�ݒ�
			m_pos.y += move_speed;
			//���]�t���O
			move_flag = true;
		}
	}
		break;
	}
	}
	//�A�j���[�V�����̕ύX
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
	DrawRect();
}

//�G�̍U��
void Enemy::Attack()
{
	Task* p = TaskManager::FindObject(eType_Player);
	attack_Timer++;
	if (attack_Timer >= attack_Interval)
	{
		CVector3D bullet_Position = m_pos;
		CVector3D bullet_Direction = (m_pos);
		attack_Timer = 0.0f;
		attack_no++;
		switch (Enemy_Number)
		{
		case 0:
		{
			if (m_flip)
			{
				//�G�̍U���̐���
				new EnemyAttack(m_pos + CVector2D(+190, 0), attack_no, 0, m_flip);
				{
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 0, m_flip);
				{
				}
			}
		}
		break;
		case 1:
		{
			if (m_flip)
			{
				//�G�̍U���̐���
				new EnemyAttack(m_pos + CVector2D(+190, 0), attack_no, 1, m_flip);
				{
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 1, m_flip);
				{
				}
			}
		}
		break;
		case 2:
		{
			if (m_flip)
			{
				//�G�̍U���̐���
				new EnemyAttack(m_pos + CVector2D(+190, 0), attack_no, 2, m_flip);
				{
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 2, m_flip);
				{
				}
			}
		}
		break;
		}
	
	}
}

//�G�̓����蔻��
void Enemy::Collision(Task* b)
{

	switch (b->m_type)
	{
	case eType_Fish:
	{

		if (Fish* e = dynamic_cast<Fish*>(b))
		{
			if (m_damage_no != e->GetAttackNo() && ObjectBase::CollisionRect(this, e))
			{
				m_damage_no = e->GetAttackNo();
				m_hp - 1;
				if (m_hp <= 0)
				{
					GiveScore(100);
					e->Kill();
				}
			}
		}
	}
	break;
	}
}


