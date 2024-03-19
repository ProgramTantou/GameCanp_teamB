#include "Enemy.h"
#include "EnemyAttack.h"
#include "TaskManager.h"
#include "Fish.h"
#include "GameData.h"
#include "AnimData.h"

//コンストラクタ
Enemy::Enemy(const CVector3D& p,int enemy_number,bool flip) :ObjectBase(eType_Enemy) {
	Enemy_Number = enemy_number;
	//移動量
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
		//画像複製
		m_img = COPY_RESOURCE("Enemy1", CImage);
		//再生アニメーション
		m_img.ChangeAnimation(0);
		//座標設定
		m_pos = p;
		m_img.SetSize(512 / 2, 512 / 2);
		//中心位置設定
		m_img.SetCenter(256 / 2, 256 );
		m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 16, -256 / 16);
		//反転フラグ
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
		//画像複製
		m_img = COPY_RESOURCE("Enemy2", CImage);
		//再生アニメーション
		m_img.ChangeAnimation(0);
		//座標設定
		m_pos = p;
		m_img.SetSize(512/2, 512/2);
		//中心位置設定
		m_img.SetCenter(256 / 2, 256 );
		m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 16, -256 / 16);
		//反転フラグ
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
		//画像複製
		m_img = COPY_RESOURCE("Enemy3", CImage);
		//再生アニメーション
		m_img.ChangeAnimation(0);
		//座標設定
		m_pos = p;
		m_img.SetSize(512 / 2, 512 / 2);
		//中心位置設定
		m_img.SetCenter(256 / 2, 256);
		m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 16, -256 / 16);
		//反転フラグ
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
	//攻撃番号
	attack_no = rand();
}

//敵のHPを取得
int Enemy::GetHP()
{
	return m_hp;
}

//敵の動きまとめてる処

void Enemy::EnemyMove() {
	m_pos;
	//m_pos_old = m_pos;

	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));
	{if (player) {

		//プレイヤーと敵のX軸の距離を　＊distance(距離)　とする。
		float distance = abs(player->m_pos.x - m_pos.x);

		//プレイヤーの距離が「敵」の待機距離内に入ったら
		if (distance <= waitdistance) {

			//左移動
			if (player->m_pos.x < m_pos.x - 64) {
				//移動量を設定
				m_pos.x += -move_speed1;
				m_flip = false;
				move_flag = true;
				Attack();
				if (m_hp >= 0)
					m_state = eState_Move;
			}
			//右移動
			if (player->m_pos.x > m_pos.x + 64) {
				//移動量を設定
				m_pos.x += move_speed1;
				//反転フラグ
				m_flip = true;
				move_flag = true;
				Attack();
				if (m_hp >= 0)
					m_state = eState_Move;

			}
			//奥移動
			if (player->m_pos.z < m_pos.z) {
				//移動量を設定
				m_pos.z += -move_speed1;
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;

			}
			//手前移動
			if (player->m_pos.z > m_pos.z) {
				//移動量を設定
				m_pos.z += move_speed1;
				//反転フラグ
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;

			}

			//上移動
			if (player->m_pos.y < m_pos.y) {
				//移動量を設定
				m_pos.y += -move_speed1;
				move_flag = true;
			}
			//下移動
			if (player->m_pos.y > m_pos.y) {
				//移動量を設定
				m_pos.y += move_speed1;
				//反転フラグ
				move_flag = true;
			}
		}
	}
	}
}
void Enemy::EnemyMove1(){
	m_pos;
	//m_pos_old = m_pos;

	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));

	{if (player) {

		//プレイヤーと敵のX軸の距離を　＊distance(距離)　とする。
		float distance = abs(player->m_pos.x - m_pos.x);

		//プレイヤーの距離が「敵」の待機距離内に入ったら
		if (distance <= waitdistance) {

			//待機時間を超えるまで、waitTimerでカウント ＊duration(間隔)
			if (waitTimer < waitduration)
			{
				waitTimer++;
			}
			else {
				timer++;
				attack_Timer++;

				//左移動
				if (player->m_pos.x < m_pos.x - 64)
				{
					//移動量を設定
					m_pos.x -= (move_speed + 0.5);
					m_flip = false;
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}

				}
				//右移動
				if (player->m_pos.x > m_pos.x + 64)
				{
					//移動量を設定
					m_pos.x += (move_speed + 0.5);
					//反転フラグ
					m_flip = true;
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}
				}
				//奥移動
				if (player->m_pos.z < m_pos.z)
				{
					//移動量を設定
					m_pos.z += -(move_speed + 0.5);
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}
				}

				//手前移動
				if (player->m_pos.z > m_pos.z)
				{
					//移動量を設定
					m_pos.z += (move_speed + 0.5);
					//反転フラグ
					move_flag = true;
					if (m_hp >= 0)
					{
						m_state = eState_Move;
					}
				}

				//上移動
				if (player->m_pos.y < m_pos.y)
				{
					//移動量を設定
					m_pos.y += -move_speed;
					move_flag = true;
				}
				//下移動
				if (player->m_pos.y > m_pos.y)
				{

					//移動量を設定
					m_pos.y += move_speed;
					//反転フラグ
					move_flag = true;
				}

				//ある程度の距離になったら攻撃をする。(200以下)
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

				//5秒間動く
				if (timer >= 300)
				{
					//待機時間を超えるまで~ に戻る
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

	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	//const float jump_pow = 12;
	ObjectBase* player = dynamic_cast <ObjectBase*>(TaskManager::FindObject(eType_Player));

	{if (player) {

		//プレイヤーと敵のX軸の距離を　＊distance(距離)　とする。
		float distance = abs(player->m_pos.x - m_pos.x);

		//プレイヤーの距離が「敵」の待機距離内に入ったら
		if (distance <= waitdistance) {

			//左移動
			if (player->m_pos.x < m_pos.x - 64)
			{
				//移動量を設定
			//	if(isCharging=false)
				m_pos.x -= (move_speed + 0.5);
				m_flip = false;
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;

			}
			//右移動
			if (player->m_pos.x > m_pos.x + 64)
			{
				//移動量を設定
				m_pos.x += (move_speed - 0.5);
				//反転フラグ
				m_flip = true;
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;
			}

			//奥移動
			if (player->m_pos.z < m_pos.z)
			{
				//移動量を設定
				m_pos.z += (-move_speed + 0.5);
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;
			}
			//手前移動
			if (player->m_pos.z > m_pos.z)
			{
				//移動量を設定
				m_pos.z += (move_speed - 0.5);
				//反転フラグ
				move_flag = true;
				if (m_hp >= 0)
					m_state = eState_Move;
			}

			//上移動
			if (player->m_pos.y < m_pos.y)
			{
				//移動量を設定
				m_pos.y += (-move_speed + 0.5);
				move_flag = true;
			}
			//下移動
			if (player->m_pos.y > m_pos.y)
			{
				//移動量を設定
				m_pos.y += (move_speed - 0.5);
				//反転フラグ
				move_flag = true;
			}

			//ここから突進処理

				//突進不可だったら
			if (!isCharging)
			{
				timer++;//時間経過
				//インターバルを過ぎたら
				if (timer >= ChargingInterval)
				{
					isCharging = true;		//突進可能
					timer = 0;
				}
			}
			else
			{
				if (player)
				{

					//プレイヤーのほうへ突進する。
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
				//プレイヤーとの距離が30以下なら
				if (abs(player->m_pos.x - m_pos.x) <= 30)
				{
					isCharging = false;		//突進不可
				}
			}

			//ある程度の距離になったら攻撃をする。(30以下)
			if (abs(player->m_pos.x - m_pos.x) <= 30) {
				Attack();
				m_pos.x += 0;
			}
		}
	}
	}
}

//スコア加算
void Enemy::GiveScore(int Score)
{
	GameData::m_score += (Score);
}

//死亡処理
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
	
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
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
	//アニメーションの変更
	m_img.ChangeAnimation(move_dir);
	//アニメーション更新
	*/
	m_img.UpdateAnimation();
}

void Enemy::Render() {
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//DrawRect();
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
				//敵の攻撃の生成
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
				//敵の攻撃の生成
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

//敵の当たり判定
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


