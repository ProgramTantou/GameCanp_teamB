#include"Fish.h"
#include"Player.h"
#include"GameData.h"
#include"AnimData.h"
#include"Enemy.h"
#include"Effect.h"
#include"TaskManager.h"

//コンストラクタ
Fish::Fish(const CVector3D& pos, Task* b, int fish, bool flip, int attack_no, int type) :ObjectBase(type)
{
	m_State = e_Move;
	m_fish = fish;
	switch (m_fish)
	{
	case eFish_1:
		//ピンク
		m_img = COPY_RESOURCE("Fish_1", CImage);
		break;
	case eFish_2:
		//青
		m_img = COPY_RESOURCE("Fish_2", CImage);
		break;
	case eFish_3:
		//たこ
		m_img = COPY_RESOURCE("Fish_3", CImage);
		break;
	default:
		printf("a");
		break;
	}
	m_pos = pos;
	player = b;
	m_flip = flip;
	m_attack_no = attack_no;
	m_img.ChangeAnimation(0);
	m_img.SetSize(512 / 2, 512 / 2);
	m_img.SetCenter(512 / 8, 512 / 8);
	m_rect = CRect3D(-512 / 8, -512 / 8, 512 / 8, 512 / 8, 256 / 8, -256 / 8);
	m_screen = false;
	int cnt = 0;
	int time = 0;
	move_speed = 0;
}

void Fish::Move() {
	
	if (m_type == eType_Fish)
	{
		if (m_flip == true)
		{
			move_speed = -6;
		}
		else if (m_flip == false)
		{
			move_speed = 6;
		}
		if (m_fish == eFish_1)
		{
			m_img.ChangeAnimation(eMove, false);
			m_pos.x += (move_speed + 1);
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
		else if (m_fish == eFish_2)
		{
			m_img.ChangeAnimation(eMove, false);
			m_pos.x += (move_speed + 2);
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
		else if (m_fish == eFish_3)
		{
			m_img.ChangeAnimation(eMove, false);
			m_pos.x += abs(sin(DtoR(time))) * 6;
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
	}
}

void Fish::Attack() {
	
	if (m_type == eType_Player_Attack && m_flip == true)
	{
		move_speed = -3;
		if (m_fish == eFish_1)
		{
			m_img.ChangeAnimation(eAttack, true);
			m_pos.x += (move_speed -2);
			cnt++;
			if (cnt >= 300)
			{
				cnt = 0;
				m_type = eType_Fish;
				m_State = e_Down;
			}
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
		else if (m_fish == eFish_2)
		{
		m_img.ChangeAnimation(eAttack, true);
			m_pos.x += (move_speed -3);
			cnt++;
			if (cnt >= 300)
			{
				cnt = 0;
				m_type = eType_Fish;
				m_State = e_Down;
			}
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
		else if (m_fish == eFish_3)
		{	
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += abs(sin(DtoR(time))) * -6;
			cnt++;
			if (cnt >= 300)
			{
				cnt = 0;
				m_type = eType_Fish;
				m_State = e_Down;
			}
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
	}
	else if (m_type == eType_Player_Attack && m_flip == false)
	{
		move_speed = 3;
		if (m_fish == eFish_1)
		{
			m_img.ChangeAnimation(eAttack, true);
			m_pos.x += (move_speed + 2);
			cnt++;
			if (cnt >= 300)
			{
				cnt = 0;
				m_type = eType_Fish;
				m_State = e_Down;
			}
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
		else if (m_fish == eFish_2)
		{
			m_img.ChangeAnimation(eAttack, true);
			m_pos.x += (move_speed + 3);
			cnt++;
			if (cnt >= 300)
			{
				cnt = 0;
				m_type = eType_Fish;
				m_State = e_Down;
			}
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
		}
		else if (m_fish == eFish_3)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += abs(sin(DtoR(time))) * 6;
			cnt++;
			if (cnt >= 300)
			{
				cnt = 0;
				m_type = eType_Fish;
				m_State = e_Down;
				
			}
			if (m_img.CheckAnimationEnd())
			{
				m_State = e_Move;
			}
			
		}
	}
}

void Fish::Down()
{
	m_img.ChangeAnimation(eDown, false);

	if (m_img.CheckAnimationEnd())
	{
		Kill();
	}
}

//更新
void Fish::Update()
{
	time++;
	m_img.UpdateAnimation();
	switch (m_State)
	{
	case e_Move:
		Move();
		break;
	case e_Attack:
		Attack();
	case e_Down:
		Down();
		break;
	}
	if (m_type == eType_Player_Attack)
	{
		Attack();
	}
	if (!TaskManager::FindObject(eType_Player))
	{
		Kill();
	}
	
	if (GameData::death_flag == true || GameData::clear_flag == true)
	{
		Kill();
	}
	if (m_scroll.x + 2100 < m_pos.x)
	{
		Kill();
	}
	else if (m_scroll.x - 300 > m_pos.x)
	{
		Kill();
	}
}



//描画
void Fish::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}
//衝突判定
void Fish::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Enemy:
		if (Enemy* e = dynamic_cast<Enemy*>(b))
		{
			if (m_type == eType_Player_Attack && ObjectBase::CollisionRect(this, e))
			{
				switch (m_fish)
				{
				case eFish_1:
					//ピンク
					new Effect("Effect_1", m_pos, m_flip);
					m_type = eType_Fish;
					m_State = e_Down;
					break;
				case eFish_2:
					//青
					new Effect("Effect_2", m_pos, m_flip);
					m_type = eType_Fish;
					m_State = e_Down;
					break;
				case eFish_3:
					//たこ
					m_type = eType_Fish;
					m_State = e_Down;
					break;
				default:
					break;
				}
			}
		}
		break;
	}
}