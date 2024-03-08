#include"Fish.h"

TexAnim fish[] = {
{0,6},{1,6},{2,6},{3,6}
};

extern TexAnimData fish_anim_data[] = {
	{fish,sizeof(fish) / sizeof(fish[0])},
};

Fish::Fish(const CVector2D& pos,int fish) :Base(eType_Fish) 
{
	m_fish = fish;
	switch (m_fish) 
	{
	case eFish_1:
		//m_img.Load("",fish_anim_data , , );
		break;
	case eFish_2:
		//m_img.Load("",fish_ainm_data, , );
		break;
	case eFish_3:
		//m_img.Load("",fish_ainm_data, , );
		break;
	}
	m_pos = pos;
	m_img.ChangeAnimation(0, true);
	//m_img.SetSize();
	//m_img.SetCenter(,);
	int move_speed = 3;
	if (m_fish == eFish_1) 
	{
		m_pos.x += (move_speed + 3);
	}
	else if (m_fish == eFish_2) 
	{
		m_pos.x += (move_speed + 2);
	}
	else 
	{
		m_pos.x += (move_speed + 1);
	}

}

void Fish::Update()
{
	m_img.UpdateAnimation();
	if (m_pos.x < 0)
	{
		SetKill();
	}
	if (m_pos.x > 1920) 
	{
		SetKill();
	}


}

void Fish::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Fish::Collision(Base* b)
{

}