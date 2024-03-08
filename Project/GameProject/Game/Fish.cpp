#include"Fish.h"

/*TexAnim Idle[] = {
{0,6},{1,6},{2,6},{3,6}
};

extern TexAnimData fish_anim_data[] = {
	{Idle,sizeof(Idle) / sizeof(Idle[0])},
};*/

Fish::Fish(const CVector2D& pos,int fish) :Base(eType_Fish) 
{
	m_fish = fish;
}

void Fish::Update()
{
}

void Fish::Draw()
{

}

void Fish::Collision(Base* b)
{

}