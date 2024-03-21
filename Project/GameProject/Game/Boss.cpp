#include "Boss.h"
#include "Fish.h"
#include "Player.h"
#include "GameData.h"
#include "EnemyAttack.h"
#include "TaskManager.h"
#include "Resoult.h"
#include "PlayerAttack.h"


Boss::Boss(const CVector3D& pos, bool flip) :ObjectBase(eType_Enemy) {
	m_pos = pos;
	m_flip = flip;
	m_img = COPY_RESOURCE("Boss", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(512, 512);
	m_img.SetCenter(256/2, 256);
	m_rect = CRect3D(-256, -256, 256, 256,256,-256);
	m_hp = 7;
	Timer = 0;
	DropTimer = 0;
	attack_no = rand();
	attack_Timer = 0.0f;
	attack_Interval = 60.0f;
	interval = 0;
	intervalmax = 60;
	randamAction = 0;
}

Boss::~Boss() {
	GameData::clear_flag = true;
}

int Boss::GetHP() 
{
	return m_hp;
}

void Boss::GiveScore(int Score)
{
	GameData::m_score += Score;
}

void Boss::Dead() {
	Kill();
}

void Boss::Move() {
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject (eType_Player));
		const float Boss_Speed = 3;
		if (player)
		{
			//���ړ�
			if (player->m_pos.x < m_pos.x - 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += -Boss_Speed;
				m_flip = false;

			}
			//�E�ړ�
			if (player->m_pos.x > m_pos.x + 64) {
				//�ړ��ʂ�ݒ�
				m_pos.x += Boss_Speed;
				//���]�t���O
				m_flip = true;


			}
			//���ړ�
			if (player->m_pos.z < m_pos.z) {
				//�ړ��ʂ�ݒ�
				m_pos.z += -Boss_Speed;


			}
			//��O�ړ�
			if (player->m_pos.z > m_pos.z) {
				//�ړ��ʂ�ݒ�
				m_pos.z += Boss_Speed;
				//���]�t���O


			}

			//��ړ�
			if (player->m_pos.y < m_pos.y) {
				//�ړ��ʂ�ݒ�
				m_pos.y += -Boss_Speed;

			}
			//���ړ�
			if (player->m_pos.y > m_pos.y) {
				//�ړ��ʂ�ݒ�
				m_pos.y += Boss_Speed;
				//���]�t���O

			}
		}
}
void Boss::Move1() {
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
	const float Boss_Speed = 3;

	//���ړ�
	if (player) {
		if (player->m_pos.z < m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += -Boss_Speed;

		}
		//��O�ړ�
		if (player->m_pos.z > m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += Boss_Speed;

		}
		//��ړ�
		if (player->m_pos.y < m_pos.y) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -Boss_Speed;

		}
		//���ړ�
		if (player->m_pos.y > m_pos.y) {
			//�ړ��ʂ�ݒ�
			m_pos.y += Boss_Speed;

		}
	}
}
void Boss::Move2() {
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
	const float Boss_Speed = 3;
	const float Boss_Speed1 = 6;
	if (player)
	{
		//���ړ�
		if (player->m_pos.x < m_pos.x - 64) {
			//�ړ��ʂ�ݒ�
			m_pos.x -= (Boss_Speed1);
			m_flip = false;

		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x + 64) {
			//�ړ��ʂ�ݒ�
			m_pos.x += (Boss_Speed1);
			//���]�t���O
			m_flip = true;

		}
		//���ړ�
		if (player->m_pos.z < m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z -= (Boss_Speed1);


		}
		//��O�ړ�
		if (player->m_pos.z > m_pos.z) {
			//�ړ��ʂ�ݒ�
			m_pos.z += (Boss_Speed1);
			//���]�t���O

		}
	}
}

void Boss::Update()
{	
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
	const float Boss_Speed = 3;
		if (interval >= intervalmax)
		{
			if (Timer == 0)
			{
				randamAction = rand() % 3;
			}

			switch (randamAction)
			{
			case 0://�{�X�̋ߐڍU��
				if (player)
				{
					Move1();
					Timer++;
					{
						if (player->m_pos.x < m_pos.x + 720)
						{
							m_pos.x -= (Boss_Speed + 3);
						}
					}
					Attack();
				}
					//printf("A");
				break;
			case 1://�{�X�̉������U��
				Timer++;
				//printf("B");
				Move1();
				Timer++;
				{
					if (player)
					{
						if (player->m_pos.x > m_pos.x - 900)
						{
							m_pos.x += (Boss_Speed + 3);
						}
					}
				}
				Attack();
				break;
			case 2://�{�X�̏�󂩂痎�����Ă���U��
				Timer++;
				DropTimer++;
				Move2();
				if (DropTimer < 90)
				{
				
					m_pos.y -= 10;
				}
				else if (DropTimer >= 90)
				{
					m_pos.y += 10;
				}
				 if (DropTimer >=120)
				{
					Attack();
				}
				//printf("C");
				break;
			}

			if (Timer >= 180)
			{
				interval = 0;
				Timer = 0;
				DropTimer = 0;
				
			}
		}
		else
		{
			interval++;
		}
		
		if(player)
		if (player->m_pos.x > m_pos.x)
		{
			m_flip = true;
		}
		else
		{
			m_flip = false;
		}

	//�A�j���[�V�����̕ύX
	m_img.ChangeAnimation(move_dir);
	//�A�j���[�V�����̍X�V
	m_img.UpdateAnimation();
}

void Boss::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//DrawRect();
}

void Boss::Attack()
{
	attack_no++;
	attack_Timer++;
	Task* p = TaskManager::FindObject(eType_Player);
	randamAction;

	if (attack_Timer >= attack_Interval)
	{
		attack_Timer = 0.0f;
		switch (randamAction)
		{
		case 0:
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
			break;
		case 1:
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
			break;
		case 2:
			if (m_flip)
			{
				//�G�̍U���̐���
				new EnemyAttack(m_pos + CVector2D(100, 100), attack_no, 1, m_flip);
				{
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(100, 100), attack_no, 1, m_flip);
				{
				}
			}
			break;
		}
	}
}

void Boss::Collision(Task* b) 
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
					Dead();
					GiveScore(500);
				}
				f->Kill();
			}
		}
		break;
	}
	case eType_Player_near:
		if (PlayerAttack* n = dynamic_cast<PlayerAttack*>(b))
		{
			if (m_Damage_no != n->GetAttackNo() && ObjectBase::CollisionRect(this, n))
			{
				m_Damage_no = n->GetAttackNo();
				m_hp -= 1;
				if (m_hp <= 0)
				{
					Dead();
					GiveScore(500);
					GameData::clear_flag = true;
					new Resoult(2);
				}
				n->Kill();
			}
		}
		break;
	}
	}


