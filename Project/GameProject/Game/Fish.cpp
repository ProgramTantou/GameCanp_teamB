#include"Fish.h"
#include"Player.h"
#include"GameData.h"
#include"AnimData.h"

int frm = 10;

static TexAnim fishRun[] = {
	{0,frm},
	{1,frm},
	{2,frm},
};

static TexAnim fishAttack00[] = {
	{24,frm},
	{25,frm},
	{26,frm},
};

static TexAnim fishDown[] = {
	{32,frm},
	{33,frm},
	{34,frm},
};

TexAnimData fish_anim_data[] = {
	ANIMDATA(fishRun),
	ANIMDATA(fishAttack00),
	ANIMDATA(fishDown),
};
//コンストラクタ
Fish::Fish(const CVector3D& pos,Task*b, int fish, bool flip, int attack_no,int type) :ObjectBase(type)
{
	m_fish = fish;
	switch (m_fish)
	{
	case eFish_1:
		//ピンク
		m_img = COPY_RESOURCE("Fish_1", CImage);
		break;
	case eFish_2:
		//たこ
		m_img = COPY_RESOURCE("Fish_2", CImage);
		break;
	case eFish_3:
		//ふぐ
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
//更新
void Fish::Update()
{
	if (GameData::death_flag == true || GameData::clear_flag == true)
	{
		Kill();
	}

	if (m_scroll.x + 1920 < m_pos.x) 
	{
		Kill();
	}
	else if (m_scroll.x > m_pos.x)
	{
		Kill();
	}

	time++;
	m_img.UpdateAnimation();

	if (eType_Fish)
	{
		move_speed = -3;
		if (m_fish == eFish_1)
		{
			m_img.ChangeAnimation(eMove, false);
			m_pos.x += (move_speed + 1);
			cnt++;
			/*if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
		else if (m_fish == eFish_2)
		{
			m_img.ChangeAnimation(eMove, false);
			m_pos.x += abs(sin(DtoR(time))) * 5;
			cnt++;
			/* if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
		else if (m_fish == eFish_3)
		{
			m_img.ChangeAnimation(eMove, false);
			m_pos.x += (move_speed + 0.5);
			cnt++;
			/*if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
	}

	
	if (eType_Player_Attack&&m_flip == true) 
	{
		move_speed = -3;
		if (m_fish == eFish_1)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += (move_speed + 1);
			cnt++;
			/*if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
		else if (m_fish == eFish_2)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += abs(sin(DtoR(time))) * 5;
			cnt++;
			/* if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
		else if (m_fish == eFish_3)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += (move_speed + 0.5);
			cnt++;
			/*if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
	}
	else if (eType_Player_Attack && m_flip == false) 
	{
		move_speed = 3;
		if (m_fish == eFish_1)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += (move_speed + 1);
			cnt++;
			/*if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
		else if (m_fish == eFish_2)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += abs(sin(DtoR(time))) * 5;
			cnt++;
			/* if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
		else if (m_fish == eFish_3)
		{
			m_img.ChangeAnimation(eAttack, false);
			m_pos.x += (move_speed + 0.5);
			cnt++;
			/*if (cnt >= 180)
			{
				Kill();
				cnt = 0;
			}*/
		}
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

}
