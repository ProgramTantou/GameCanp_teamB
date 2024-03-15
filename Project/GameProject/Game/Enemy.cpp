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

//コンストラクタ
Enemy::Enemy(const CVector3D& p,int enemy_number,bool flip) :ObjectBase(eType_Enemy) {
	Enemy_Number = enemy_number;
	//移動量
	  move_speed = 2;
	  move_speed1 = 1;
	  move_speedtossin = 4;
	  timer = 0;
	  m_damage_no = rand();
	switch (Enemy_Number)
	{
	case 0:
	{
		//画像複製
		m_img = COPY_RESOURCE("Enemy1", CImage);
		//再生アニメーション
		m_img.ChangeAnimation(0);
		//座標設定
		m_pos = p;
		m_img.SetSize(256, 256);
		//中心位置設定
		m_img.SetCenter(256 / 2, 256 / 2);
		m_rect = CRect3D(-256 / 2,-256 / 4,256 / 2,256 / 4, 256 / 2,-256 / 2);
		//反転フラグ
		m_flip = flip;
		m_Attack_no = rand();
		
		m_hp = 2;
		attack_Timer = 0.0f;
		attack_Interval = 120.0f;
		break;
	}
	case 1:
	{
		//画像複製
		m_img = COPY_RESOURCE("Enemy2", CImage);
		//再生アニメーション
		m_img.ChangeAnimation(0);
		//座標設定
		m_pos = p;
		m_img.SetSize(256, 256);
		//中心位置設定
		m_img.SetCenter(256 / 2, 256 / 2);
		m_rect = CRect3D(-256 / 2 , -256 / 4, 256 / 2, 256 / 4,256 , -256 );
		//反転フラグ
		m_flip = flip;
		m_Attack_no = rand();
		
		m_hp = 3;
		attack_Timer = 0.0f;
		attack_Interval = 150.0f;
		break;
	}
	case 2:
	{
		//画像複製
		m_img = COPY_RESOURCE("Enemy3", CImage);
		//再生アニメーション
		m_img.ChangeAnimation(0);
		//座標設定
		m_pos = p;
		m_img.SetSize(256, 256);
		//中心位置設定
		m_img.SetCenter(256 / 2, 256 / 2);
		m_rect = CRect3D(-256 / 2, -256 / 2, 256 / 2, 256 / 2, 256 / 2, -256 / 2);
		//反転フラグ
		m_flip = flip;
		m_Attack_no = rand();

		m_hp = 1;
		attack_Timer = 0.0f;
		attack_Interval = 120.0f;
		break;
	}

	}
	//攻撃番号
	attack_no = rand();
}

//敵のHPを取得
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
	
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));
	switch (Enemy_Number)
	{
	case 0:
	{if (player) {
		//左移動
if (player->m_pos.x < m_pos.x - 64) {
	//移動量を設定
	m_pos.x += -move_speed1;
	m_flip = false;
	move_flag = true;
	Attack();
}
//右移動
if (player->m_pos.x > m_pos.x + 64) {
	//移動量を設定
	m_pos.x += move_speed1;
	//反転フラグ
	m_flip = true;
	move_flag = true;
	Attack();
	
}
//奥移動
if (player->m_pos.z < m_pos.z) {
	//移動量を設定
	m_pos.z += -move_speed1;
	move_flag = true;
	
}
//手前移動
if (player->m_pos.z > m_pos.z) {
	//移動量を設定
	m_pos.z += move_speed1;
	//反転フラグ
	move_flag = true;
	
}

//上移動
if (player->m_pos.y - 70 < m_pos.y) {
	//移動量を設定
	m_pos.y += -move_speed1;
	move_flag = true;
}
//下移動
if (player->m_pos.y + 70 > m_pos.y) {
	//移動量を設定
	m_pos.y += move_speed1;
	//反転フラグ
	move_flag = true;
}

	}
	break;
	}
	case 1:

	{if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			//移動量を設定
			m_pos.x -= move_speed;
			m_flip = false;
			move_flag = true;
			Attack();

		}
		//右移動
		if (player->m_pos.x > m_pos.x + 64) {
			//移動量を設定
			m_pos.x += move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
			Attack();

		}
		//奥移動
		if (player->m_pos.z < m_pos.z) {
			//移動量を設定
			m_pos.z += -move_speed;
			move_flag = true;

		}
		//手前移動
		if (player->m_pos.z > m_pos.z) {
			//移動量を設定
			m_pos.z += move_speed;
			//反転フラグ
			move_flag = true;
		}

		//上移動
		if (player->m_pos.y < m_pos.y) {
			//移動量を設定
			m_pos.y += -move_speed;
			move_flag = true;
		}
		//下移動
		if (player->m_pos.y > m_pos.y) {
			//移動量を設定
			m_pos.y += move_speed;
			//反転フラグ
			move_flag = true;
		}
		

	}
		break;
	}
	case 2:
	{if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			//移動量を設定
			m_pos.x += -move_speed;
			m_flip = false;
			move_flag = true;
		}
		//右移動
		if (player->m_pos.x > m_pos.x + 64) {
			//移動量を設定
			m_pos.x += move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		//奥移動
		if (player->m_pos.z < m_pos.z) {
			//移動量を設定
			m_pos.z += -move_speed;
			move_flag = true;
		}
		//手前移動
		if (player->m_pos.z > m_pos.z) {
			//移動量を設定
			m_pos.z += move_speed;
			//反転フラグ
			move_flag = true;
		}

		//上移動
		if (player->m_pos.y - 120 < m_pos.y) {
			//移動量を設定
			m_pos.y += -move_speed;
			move_flag = true;
		}
		//下移動
		if (player->m_pos.y > m_pos.y) {
			//移動量を設定
			m_pos.y += move_speed;
			//反転フラグ
			move_flag = true;
		}
	}
		break;
	}
	}
	//アニメーションの変更
	m_img.ChangeAnimation(move_dir);
	//アニメーション更新
	m_img.UpdateAnimation();
}

void Enemy::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	DrawRect();
}

//敵の攻撃
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
				//敵の攻撃の生成
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
				//敵の攻撃の生成
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
				//敵の攻撃の生成
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

//敵の当たり判定
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


