#include "Boss.h"
#include "Fish.h"
#include "Player.h"
#include "GameData.h"
#include "EnemyAttack.h"
#include "TaskManager.h"
#include "Resoult.h"
#include "PlayerAttack.h"
#include "AnimData.h"

//コンストラクタ
Boss::Boss(const CVector3D& pos, bool flip) :ObjectBase(eType_Enemy) {
	m_pos = pos;
	m_flip = flip;
	m_img = COPY_RESOURCE("Boss", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(512, 512);
	m_img.SetCenter(256/2, 256);
	m_rect = CRect3D(-256, -256, 256, 256,256,-256);
	m_hp = 14;
	Timer = 0;
	DropTimer = 0;
	attack_no = rand();
	attack_Timer = 0.0f;
	attack_Interval = 60.0f;
	interval = 0;
	intervalmax = 60;
	randamAction = 0;
	m_state = eStete_Move;
}

//デストラクタ
Boss::~Boss() {

}

//HP取得
int Boss::GetHP() 
{
	return m_hp;
}

//スコア加算
void Boss::GiveScore(int Score)
{
	GameData::m_score += Score;
}

//死亡
void Boss::Dead() {
	m_img.ChangeAnimation(eState_Dead, false);
	if (m_img.CheckAnimationEnd())
	{
		Kill();		
		GameData::clear_flag = true;
		new Resoult(2);	
		TaskManager::SelectKill(eType_Player);
	}
}

//ボスの動き　その1
void Boss::Move() {
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject (eType_Player));
		const float Boss_Speed = 3;
		if (player)
		{
			//左移動
			if (player->m_pos.x < m_pos.x - 64) {
				//移動量を設定
				m_pos.x += -Boss_Speed;
				m_flip = false;

			}
			//右移動
			if (player->m_pos.x > m_pos.x + 64) {
				//移動量を設定
				m_pos.x += Boss_Speed;
				//反転フラグ
				m_flip = true;

			}
			//奥移動
			if (player->m_pos.z < m_pos.z) {
				//移動量を設定
				m_pos.z += -Boss_Speed;
				

			}
			//手前移動
			if (player->m_pos.z > m_pos.z) {
				//移動量を設定
				m_pos.z += Boss_Speed;
				//反転フラグ
			

			}

			//上移動
			if (player->m_pos.y < m_pos.y) {
				//移動量を設定
				m_pos.y += -Boss_Speed;

			}
			//下移動
			if (player->m_pos.y > m_pos.y) {
				//移動量を設定
				m_pos.y += Boss_Speed;
				//反転フラグ

			}

		}
}
//その２
void Boss::Move1() {
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
	const float Boss_Speed = 3;

	//奥移動
	if (player) {
		if (player->m_pos.z < m_pos.z) {
			//移動量を設定
			m_pos.z += -Boss_Speed;
			
		}
		//手前移動
		if (player->m_pos.z > m_pos.z) {
			//移動量を設定
			m_pos.z += Boss_Speed;
		
		}
		//上移動
		if (player->m_pos.y < m_pos.y) {
			//移動量を設定
			m_pos.y += -Boss_Speed;

		}
		//下移動
		if (player->m_pos.y > m_pos.y) {
			//移動量を設定
			m_pos.y += Boss_Speed;

		}
	}
}
//その3
void Boss::Move2() {
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
	const float Boss_Speed = 3;
	const float Boss_Speed1 = 6;
	if (player)
	{
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			//移動量を設定
			m_pos.x -= (Boss_Speed1);
			m_flip = false;
			

		}
		//右移動
		if (player->m_pos.x > m_pos.x + 64) {
			//移動量を設定
			m_pos.x += (Boss_Speed1);
			//反転フラグ
			m_flip = true;
			
		}
		//奥移動
		if (player->m_pos.z < m_pos.z) {
			//移動量を設定
			m_pos.z -= (Boss_Speed1);
		

		}
		//手前移動
		if (player->m_pos.z > m_pos.z) {
			//移動量を設定
			m_pos.z += (Boss_Speed1);
			//反転フラグ
		

		}
	}
}

void Boss::Update()
{	

	//ここから　ボスの動き　その４
	ObjectBase* player = dynamic_cast<ObjectBase*>(TaskManager::FindObject(eType_Player));
	const float Boss_Speed = 3;
		if (interval >= intervalmax)
		{
			if (m_hp >= 1) 
			{
				if (Timer == 0)
				{
					randamAction = rand() % 3;
				}
			}

			switch (randamAction)
			{
			case 0://ボスの遠距離攻撃　(左)
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
					
					{
						m_state = eState_Attack;
						if (m_hp <= 0)
						{
							m_state = eState_Dead;
						}
					}
				}
					//printf("A");
				break;
			case 1://ボスの遠距離攻撃 　(右)
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
			
			
				{
					m_state = eState_Attack;
					if (m_hp <= 0)
					{
						m_state = eState_Dead;
					}
				}
				break;
			case 2://ボスの上空から落下してくる攻撃
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
				 if (m_hp <= 0) {
					 m_state = eState_Dead;
				 }
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

		

		switch (m_state) {
		case eStete_Move:
			break;
		case eState_Attack:
			Attack();
			break;
		case eState_Dead:
			Dead();
			break;
		}

		//HPが半分となったら、第二形態
		if (m_hp <= 7 && m_hp > 0)
		{
			m_img.ChangeAnimation(eState_Attack, true);
		}

		//ここまで　ボスの動き　その4

	//アニメーションの更新
	m_img.UpdateAnimation();
}

void Boss::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//DrawRect();
}

//攻撃
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
				//敵の攻撃の生成
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 0, m_flip);
				if (m_hp <= 7) {
					new EnemyAttack(m_pos+CVector2D(0,100), attack_no, 0, m_flip);
				}
				
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 0, m_flip);
				if (m_hp <= 7) {
					new EnemyAttack(m_pos + CVector2D(0, 100), attack_no, 0, m_flip);
				}

			}
			break;
		case 1:
			if (m_flip)
			{
				//敵の攻撃の生成
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 0, m_flip);
				if (m_hp <= 7) {
					new EnemyAttack(m_pos + CVector2D(0, 100), attack_no, 0, m_flip);
				}
			}
			else
			{
				new EnemyAttack(m_pos + CVector2D(0, 0), attack_no, 0, m_flip);
				if (m_hp <= 7) {
					new EnemyAttack(m_pos + CVector2D(0, 100), attack_no, 0, m_flip);
				}
			}
			break;
		case 2:
			if (m_flip)
			{
				//敵の攻撃の生成
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

//当たり判定
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
				m_state = eState_Damage;
				if (m_hp <= 0)
				{
					if (m_hp > -1)
					{
						m_state = eState_Dead;
						GiveScore(500);
					}
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
					if (m_hp > -1)
					{
						m_state = eState_Dead;
						GiveScore(500);
					
					}
				}
				n->Kill();
			}
		}
		break;
	}
	}


