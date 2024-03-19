#include "Enemy.h"
#include "EnemyAttack.h"
#include "TaskManager.h"
#include "Fish.h"
#include "GameData.h"
#include "AnimData.h"

//�R���X�g���N�^
Enemy::Enemy(const CVector3D& p,int enemy_number,bool flip) :ObjectBase(eType_Enemy) {
	Enemy_Number = enemy_number;
	//�ړ���
	  move_speed = 2.0f;
	  move_speed1 = 1.0f;
	  move_charg = 6.5f;
	  timer = 0;
	  if (m_hp >= 0)
	  m_state = eState_Move;
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
		m_img.SetSize(512 / 2, 512 / 2);
		//���S�ʒu�ݒ�
		m_img.SetCenter(256 / 2, 256 );
		m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 16, -256 / 16);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		m_Damage_no = rand();
		m_hp = 2;
		attack_Timer = 0.0f;
		attack_Interval = 120.0f;
		waitdistance = 1000;
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
		m_img.SetSize(512/2, 512/2);
		//���S�ʒu�ݒ�
		m_img.SetCenter(256 / 2, 256 );
		m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 16, -256 / 16);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		m_Damage_no = rand();
		m_hp = 1;
		attack_Timer = 0.0f;
		attack_Interval = 300.0f;
		waitdistance = 1000;
		waitduration = 70;
		break;
	}
	case 2:
	{
		isCharging = false;
		//�摜����
		m_img = COPY_RESOURCE("Enemy3", CImage);
		//�Đ��A�j���[�V����
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		m_pos = p;
		m_img.SetSize(512 / 2, 512 / 2);
		//���S�ʒu�ݒ�
		m_img.SetCenter(256 / 2, 256);
		m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 16, -256 / 16);
		//���]�t���O
		m_flip = flip;
		m_Attack_no = rand();
		m_Damage_no = rand();
		m_hp = 1;
		attack_Timer = 0.0f;
		attack_Interval = 100.0f;
		ChargingInterval = 240;
		waitdistance = 800;
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

//�G�̓����܂Ƃ߂Ă鏈

void Enemy::EnemyMove() {
	m_pos;
	//m_pos_old = m_pos;

	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));
	{if (player) {

		//�v���C���[�ƓG��X���̋������@��distance(����)�@�Ƃ���B
		float distance = abs(player->m_pos.x - m_pos.x);

		//�v���C���[�̋������u�G�v�̑ҋ@�������ɓ�������
		if (distance <= waitdistance) {

			//���ړ�
			if (player->m_pos.x < m_pos.x - 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += -move_speed1;
				m_flip = false;
				move_flag = true;
				Attack();
				if (m_hp >= 0)
					m_state = eState_Move;
			}
			//�E�ړ�
			if (player->m_pos.x > m_pos.x + 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += move_speed1;
				//���]�t���O
				m_flip = true;
				move_flag = true;
				Attack();
				if (m_hp >= 0)
					m_state = eState_Move;

			}
			//���ړ�
			if (player->m_pos.z < m_pos.z) {
				//�ړ��ʂ�ݒ�
				m_pos.z += -move_speed1;
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;

			}
			//��O�ړ�
			if (player->m_pos.z > m_pos.z) {
				//�ړ��ʂ�ݒ�
				m_pos.z += move_speed1;
				//���]�t���O
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;

			}

			//��ړ�
			if (player->m_pos.y < m_pos.y) {
				//�ړ��ʂ�ݒ�
				m_pos.y += -move_speed1;
				move_flag = true;
			}
			//���ړ�
			if (player->m_pos.y > m_pos.y) {
				//�ړ��ʂ�ݒ�
				m_pos.y += move_speed1;
				//���]�t���O
				move_flag = true;
			}
		}
	}
	}
}
void Enemy::EnemyMove1(){
	m_pos;
	//m_pos_old = m_pos;

	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));

	{if (player) {

		//�v���C���[�ƓG��X���̋������@��distance(����)�@�Ƃ���B
		float distance = abs(player->m_pos.x - m_pos.x);

		//�v���C���[�̋������u�G�v�̑ҋ@�������ɓ�������
		if (distance <= waitdistance) {

			//�ҋ@���Ԃ𒴂���܂ŁAwaitTimer�ŃJ�E���g ��duration(�Ԋu)
			if (waitTimer < waitduration)
			{
				waitTimer++;
			}
			else {
				timer++;
				attack_Timer++;

				//���ړ�
				if (player->m_pos.x < m_pos.x - 64)
				{
					//�ړ��ʂ�ݒ�
					m_pos.x -= (move_speed + 0.5);
					m_flip = false;
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}

				}
				//�E�ړ�
				if (player->m_pos.x > m_pos.x + 64)
				{
					//�ړ��ʂ�ݒ�
					m_pos.x += (move_speed + 0.5);
					//���]�t���O
					m_flip = true;
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}
				}
				//���ړ�
				if (player->m_pos.z < m_pos.z)
				{
					//�ړ��ʂ�ݒ�
					m_pos.z += -(move_speed + 0.5);
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}
				}

				//��O�ړ�
				if (player->m_pos.z > m_pos.z)
				{
					//�ړ��ʂ�ݒ�
					m_pos.z += (move_speed + 0.5);
					//���]�t���O
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}
				}

				//��ړ�
				if (player->m_pos.y < m_pos.y)
				{
					//�ړ��ʂ�ݒ�
					m_pos.y += -move_speed;
					move_flag = true;
				}
				//���ړ�
				if (player->m_pos.y > m_pos.y)
				{

					//�ړ��ʂ�ݒ�
					m_pos.y += move_speed;
					//���]�t���O
					move_flag = true;
				}

				//������x�̋����ɂȂ�����U��������B(200�ȉ�)
				if (abs(player->m_pos.x - m_pos.x) <= 200)
				{
					m_state = eState_Attack01;
					m_img.ChangeAnimation(eState_Attack01, true);
					{
						Attack();
						if (m_hp <= 0)
						{
							m_state = eState_Down;
						}
					}
				}

				//5�b�ԓ���
				if (timer >= 300)
				{
					//�ҋ@���Ԃ𒴂���܂�~ �ɖ߂�
					waitTimer = 0;
					timer = 0;
				}
			}
		}

	}
	}
}
void Enemy::EnemyMove2() {
	m_pos;
	//m_pos_old = m_pos;

	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));

	{if (player) {

		//�v���C���[�ƓG��X���̋������@��distance(����)�@�Ƃ���B
		float distance = abs(player->m_pos.x - m_pos.x);

		//�v���C���[�̋������u�G�v�̑ҋ@�������ɓ�������
		if (distance <= waitdistance) {

			//���ړ�
			if (player->m_pos.x < m_pos.x - 64)
			{
				//�ړ��ʂ�ݒ�
			//	if(isCharging=false)
				m_pos.x -= (move_speed + 0.5);
				m_flip = false;
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;

			}
			//�E�ړ�
			if (player->m_pos.x > m_pos.x + 64)
			{
				//�ړ��ʂ�ݒ�
				m_pos.x += (move_speed - 0.5);
				//���]�t���O
				m_flip = true;
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;
			}

			//���ړ�
			if (player->m_pos.z < m_pos.z)
			{
				//�ړ��ʂ�ݒ�
				m_pos.z += (-move_speed + 0.5);
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;
			}
			//��O�ړ�
			if (player->m_pos.z > m_pos.z)
			{
				//�ړ��ʂ�ݒ�
				m_pos.z += (move_speed - 0.5);
				//���]�t���O
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;
			}

			//��ړ�
			if (player->m_pos.y < m_pos.y)
			{
				//�ړ��ʂ�ݒ�
				m_pos.y += (-move_speed + 0.5);
				move_flag = true;
			}
			//���ړ�
			if (player->m_pos.y > m_pos.y)
			{
				//�ړ��ʂ�ݒ�
				m_pos.y += (move_speed - 0.5);
				//���]�t���O
				move_flag = true;
			}

			//��������ːi����

				//�ːi�s��������
			if (!isCharging)
			{
				timer++;//���Ԍo��
				//�C���^�[�o�����߂�����
				if (timer >= ChargingInterval)
				{
					isCharging = true;		//�ːi�\
					timer = 0;
				}
			}
			else
			{
				if (player)
				{

					//�v���C���[�̂ق��֓ːi����B
					if (player->m_pos.x < m_pos.x)
					{
						m_pos.x -= move_charg;
						attack_Timer++;
					}
					else
					{
						m_pos.x += move_charg;
						attack_Timer++;
					}

				}
				//�v���C���[�Ƃ̋�����30�ȉ��Ȃ�
				if (abs(player->m_pos.x - m_pos.x) <= 30)
				{
					isCharging = false;		//�ːi�s��
				}
			}

			//������x�̋����ɂȂ�����U��������B(30�ȉ�)
			if (abs(player->m_pos.x - m_pos.x) <= 30) {
				Attack();
				m_pos.x += 0;
			}
		}
	}
	}
}

//�X�R�A���Z
void Enemy::GiveScore(int Score)
{
	GameData::m_score += (Score);
}

//���S����
void Enemy::Dead()
{
	m_img.ChangeAnimation(eState_Down, false);
	if (m_img.CheckAnimationEnd())
	{
		Kill();
	}
		
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
		if (m_state == eState_Move)
		EnemyMove();
	break;
	case 1:
		if (m_state == eState_Move || m_state == eState_Attack01)
			EnemyMove1();
	break;
	
	case 2:
		if (m_state == eState_Move)
			EnemyMove2();
	break;
	
	}
	
	switch (m_state)
	{
	case eState_Move:
		m_img.ChangeAnimation(eState_Move, true);
		break;
	case eState_Down:
		Dead();
		break;
	}

	/*
	//�A�j���[�V�����̕ύX
	m_img.ChangeAnimation(move_dir);
	//�A�j���[�V�����X�V
	*/
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
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 0, m_flip);
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
					timer++;
					if (timer <= 30)
					{
						m_pos.x += 0;
						if (timer >= 31)
						{
							m_pos.x += move_speed;
							timer == 0;
						}
					}
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 1, m_flip);
				{
					timer++;
					if (timer <= 30)
					{
						m_pos.x += 0;
						if (timer >= 31)
						{
							m_pos.x += move_speed;
							timer == 0;
						}
					}
				}
				
			}
		}
		break;
		case 2:
		{
			if (m_flip)
			{
				//�G�̍U���̐���
				new EnemyAttack(m_pos + CVector2D(+190, -60), attack_no, 1, m_flip);
				{
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, -60), attack_no, 1, m_flip);
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
	case eType_Player_Attack:
	{

		if (Fish* f = dynamic_cast<Fish*>(b))
		{
			if (m_Damage_no != f->GetAttackNo() && ObjectBase::CollisionRect(this, f))
			{
				m_Damage_no = f->GetAttackNo();
				m_hp -= 1;
				if (m_hp <= 0)
				{
					m_state = eState_Down;
					switch (Enemy_Number)
					{
					case 0:
					{
						GiveScore(150);
					}
					break;
					case 1:
					{
						GiveScore(100);
					}
					break;
					case 2:
					{
						GiveScore(200);
					}
					break;
					}
				
				}
				f->Kill();
			}
		}
	}
	break;
	}
}


