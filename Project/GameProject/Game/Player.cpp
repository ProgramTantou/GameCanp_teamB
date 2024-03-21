#include"Player.h"
#include"Field.h"
#include"Fish.h"
#include"PlayerAttack.h"
#include"Enemy.h"
#include"GameData.h"
#include"AnimData.h"
#include "Resoult.h"
#include "GameOver.h"
#include"EnemyAttack.h"

int Player::m_hp;
int Player::m_maxhp;

//コンストラクタ
Player::Player(const CVector3D& p,bool flip) : ObjectBase(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = p;
	m_img.ChangeAnimation(0);
	m_img.SetSize(512 / 2, 512 / 2);
	m_img.SetCenter(256/2, 256/1);
	m_img.SetRect(-512/4, -512/2, 512/4, 0);
	m_rect = CRect3D(-512 / 4, -512 / 2, 512 / 4, 0, 256 / 2, -256 / 2);
	m_flip = flip;
	m_state = eState_Move;
	m_is_ground = true;
	m_attack_no = rand();
	m_damage_no = rand();
	damage = false;
	m_damage = 0;
	m_draw_count = 1;
	m_maxhp = 10;
	m_hp = 10;
	move_speed = 6;
	jump_pow = 12;
	int i = 0;
	cnt1 = 0;
	cnt2 = 0;
	cnt3 = 0;
	creat = false;
	player_attack1 = false;
	player_attack2 = false;
	player_attack3 = false;
}
//移動
void Player::Move() {
	
	creat = false;
	//移動フラグ
	bool isMove = false;
	//移動スピード
	move_speed = 8;
	//ジャンプ力
	jump_pow=6;  
	//攻撃を受けたら減速
	if (m_damage > 0) {
		move_speed = move_speed / 2;
		jump_pow = jump_pow / 2;
		m_damage--;
	}
	
	//左向きの移動(A)
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_flip = true;
		isMove = true;
	}
	//右向きの移動(D)
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		
		m_flip = false;
		isMove = true;
	}
	//Z軸（右斜め上）(W)
	if (HOLD(CInput::eButton1) && FREE(CInput::eButton3) &&m_pos.z<80) {
		m_pos.z += move_speed = 4;
		
		m_flip = false;
		isMove = true; 
	}
	//Z軸（左斜め下）(S)
	else if (HOLD(CInput::eButton3)&&FREE(CInput::eButton1) &&m_pos.z>-280) {
		m_pos.z -= move_speed = 4;
		
		m_flip = true;
		isMove = true;
	}
	
	//ジャンプ(スペース)
	if (m_pos.y>400 && PUSH(CInput::eButton5)) 
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//ジャンプ中
	if (!m_is_ground) 
	{
		if (m_vec.y < 0)
		{
			//上昇
			m_img.ChangeAnimation(eAnimJumpUp,false);
		}
		else
		{
			//下降
			m_img.ChangeAnimation(eAnimJumpDown,false);
		}
	}
	//地面に着いている
	else 
	{
		if (isMove) 
		{
			//移動
			m_img.ChangeAnimation(eAnimRun);
		}
		else 
		{
			//待機
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
	
}


//攻撃
void Player::Attack00()
{
	m_img.ChangeAnimation(eAnimAttack00, false);
	if (m_img.GetIndex() == 3)
	{
		if (m_flip)
		{
			new PlayerAttack(CVector3D(m_pos.x - 100, m_pos.y - 70, m_pos.z), m_flip, m_attack_no);
			
		}
		else 
		{
			new PlayerAttack(CVector3D(m_pos.x + 100, m_pos.y - 70, m_pos.z), m_flip, m_attack_no);
		}
	}

	if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}
}

//Cキー
void Player::Attack01() 
{
	m_img.ChangeAnimation(eAnimAttack01, false);
	if (creat == false) {
		if (m_flip)
		{
			new Fish(CVector3D(m_pos.x + 20, m_pos.y - 130, m_pos.z),this, 0, m_flip, m_attack_no, eType_Player_Attack);
			creat = true;
			cnt1 -= 1;
		}
		else
		{
			new Fish(CVector3D(m_pos.x - 20, m_pos.y - 130, m_pos.z),this, 0, m_flip, m_attack_no, eType_Player_Attack);
			creat = true;
			cnt1 -= 1;
		}
	}
	if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}
}
//攻撃
//Vキー
void Player::Attack02()
{
	m_img.ChangeAnimation(eAnimAttack02, false);
	if (creat == false) 
	{
		if (m_flip)
		{
			new Fish(CVector3D(m_pos.x + 20, m_pos.y - 130, m_pos.z),this, 1, m_flip, m_attack_no, eType_Player_Attack);
			creat = true;
			cnt2 -= 1;
		}
		else
		{
			new Fish(CVector3D(m_pos.x - 20, m_pos.y - 130, m_pos.z),this, 1, m_flip, m_attack_no, eType_Player_Attack);
			creat = true;
			cnt2 -= 1;
		}
	}
	if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}
}
//攻撃
//Bキー
void Player::Attack03() 
{
	m_img.ChangeAnimation(eAnimAttack03, false);
	if (creat == false)
	{
		if (m_flip)
		{
			new Fish(CVector3D(m_pos.x + 20, m_pos.y - 130, m_pos.z),this, 2, m_flip, m_attack_no, eType_Player_Attack);
			creat = true;
			cnt3 -= 1;
		}
		else
		{
			new Fish(CVector3D(m_pos.x - 20, m_pos.y - 130, m_pos.z),this, 2, m_flip, m_attack_no, eType_Player_Attack);
			creat = true;
			cnt3 -= 1;
		}
	}
	if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}
}
//ダメージ
void Player::Damage()
{
	m_img.ChangeAnimation(eAnimDamage,false);
	damage = true;
	//m_hp--;
	m_damage = 60 * 2;
	
	
	/*if (m_hp <= 0)
	{
		m_state = eState_Down;
	}*/
	
	if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}
	
	//m_state = eState_Move;
}
//死亡
void Player::Down()
{
	m_img.ChangeAnimation(eAnimDown,false);
	GameData::death_flag = true;
	
	if (m_img.CheckAnimationEnd())
	{
		Kill();
		new Resoult(1);
	}
}

int Player::GetHp()
{
	return m_hp;
}

//更新
void Player::Update()
{
	if (PUSH(CInput::eMouseL))
	{
		m_state = eState_Attack00;
		m_attack_no++;
	}

	if (cnt1 > 0 && player_attack1 == true) {
		if (PUSH(CInput::eButton6)) {
			m_state = eState_Attack01;
			m_attack_no++;
		}
	}
	else if (cnt2 > 0 && player_attack2 == true)
	{
		if (PUSH(CInput::eButton7))
		{
			m_state = eState_Attack02;
			m_attack_no++;
		}
	}
	else if (cnt3 > 0 && player_attack3 == true)
	{
		if (PUSH(CInput::eButton8))
		{
			m_state = eState_Attack03;
			m_attack_no++;
		}
	}

	if (cnt1 <= 0) 
	{
		player_attack1 = false;
	}
	else if (cnt2 <= 0) 
	{
		player_attack2 = false;
	}
	else if (cnt3 <= 0) 
	{
		player_attack3 = false;
	}

	//m_pos_old = m_pos;
	switch (m_state) 
	{
	case eState_Move:
		Move(); 
		break;
	case eState_Attack00:
		Attack00();
		break;
	case eState_Attack01:
		Attack01();
		break;
	case eState_Attack02:
		Attack02();
		break;
	case eState_Attack03:
		Attack03();
		break;
	case eState_Damage:
		Damage();
		break;
	case eState_Down:
		Down();
		break;
	}
	m_img.UpdateAnimation();
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_scroll.x = m_pos.x - 1920 / 2;
	if (damage==true) {
		i++;
		if (i == 180) 
		{
			damage = false;
			i = 0;
		}
	}
}
//描画
void Player::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	//DrawRect();
	
	if(m_damage%10==0)
		m_img.Draw();
	
	//DrawRect();
}
//衝突判定
void Player::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Field* f = dynamic_cast<Field*>(b))
		{
			if (m_pos.y > f->GetGroundY()) 
			{
				m_pos.y = f->GetGroundY();
				m_vec.y = 0;
				m_is_ground = true;
			}
		}
		break;
	case eType_Enemy_Attack:
		if (EnemyAttack* e = dynamic_cast<EnemyAttack*>(b)) 
		{
			if (m_damage_no != e->GetAttackNo() && ObjectBase::CollisionRect(this, e)) 
			{
				m_damage_no = e->GetAttackNo();
				if (damage == false) {
					m_hp -= 1;
					
					//printf("a");   
					if (m_hp <= 0) 
					{
						m_state = eState_Down;
					}
					else 
					{
						m_state = eState_Damage;
					}
					e->Kill();
				}
			}
		}
		break;
	case eType_Fish:
		if (Fish* fish = dynamic_cast<Fish*>(b)) 
		{
			if (fish->m_type==eType_Fish&&ObjectBase::CollisionRect(this, fish)) 
			{
				b->Kill();
				if (fish->m_fish == eFish_1) 
				{
					player_attack1 = true;
					cnt1 += 1;
				}
				else if (fish->m_fish == eFish_2) 
				{
					player_attack2 = true;
					cnt2 += 1;
				}
				else if (fish->m_fish == eFish_3) 
				{
					player_attack3 = true;
					cnt3 += 1;
				}
			}
		}
		break;
	}
}
