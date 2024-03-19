#include"Fish.h"

//アニメーション
TexAnim fish[] = {
{0,6},{1,6},{2,6},{3,6}
};
TexAnimData fish_anim_data[] = {
   {fish,sizeof(fish) / sizeof(fish[0])},
};
//コンストラクタ
Fish::Fish(const CVector3D& pos, int fish, bool flip, int attack_no,int type) :ObjectBase(type)
{
	m_fish = fish;
	switch (m_fish)
	{
	case eFish_1:
		//うなぎ
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
	}
	m_pos = pos;
	m_flip = flip;
	m_attack_no = attack_no;
	m_img.ChangeAnimation(0, true);
	m_img.SetSize(512 / 2, 512 / 2);
	m_img.SetCenter(512 / 8, 512 / 8);
	m_rect = CRect3D(-512 / 8, -512 / 8, 512 / 8, 512 / 8, 256 / 8, -256 / 8);
	m_screen = false;
	int cnt = 0;
	int time = 0;

}
//更新
void Fish::Update()
{

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
	int move_speed = 3;
	if (m_fish == eFish_1)
	{
		m_pos.x += (move_speed + 1);
		cnt++;
		if (cnt >= 180)
		{
			//Kill();
			cnt = 0;
		}
	}
	else if (m_fish == eFish_2)
	{
		m_pos.x += abs(sin(DtoR(time))) * 5;
		cnt++;
		if (cnt >= 180)
		{
			//Kill();
			cnt = 0;
		}
	}
	else if (m_fish == eFish_3)
	{
		m_pos.x += (move_speed + 0.5);
		cnt++;
		if (cnt >= 180)
		{
			//Kill();
			cnt = 0;
		}
	}

}

//描画
void Fish::Render()
{
	if (m_fish == eFish_1)
	{
		m_img.SetAng(DtoR(360));
	}
	else if (m_fish == eFish_2)
	{
		m_img.SetAng(DtoR(270));
	}
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);

	m_img.Draw();
	//DrawRect();
}
//衝突判定
void Fish::Collision(Task* b)
{

}
