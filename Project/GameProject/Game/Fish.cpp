#include"Fish.h"

//アニメーション
TexAnim fish[] = {
{0,6},{1,6},{2,6},{3,6}
};
extern TexAnimData fish_anim_data[] = {
	{fish,sizeof(fish) / sizeof(fish[0])},
};
//コンストラクタ
Fish::Fish(const CVector3D& pos,int fish) :ObjectBase(eType_Fish) 
{
	m_fish = fish;
	switch (m_fish) 
	{
	case eFish_1:
		//m_img.Load("Image/ika.png",fish_anim_data , 766,766 );
		break;
	case eFish_2:
		//m_img.Load("Image/warasubo.png",fish_ainm_data,731 ,731 );
		break;
	case eFish_3:
		//m_img.Load("Image/nijimasu.png",fish_ainm_data,800 ,513 );
		break;
	}
	m_pos = pos;
	m_img.ChangeAnimation(0, true);
	//m_img.SetSize();
	//m_img.SetCenter(,);
	int move_speed = 3;
	if (m_fish == eFish_1) 
	{
		m_img.SetSize(766/2, 766/2);
		m_img.SetCenter(766 / 4, 766 / 4);
		m_pos.x += (move_speed + 3);
	}
	else if (m_fish == eFish_2) 
	{
		m_img.SetSize(731 / 2, 731 / 2);
		m_img.SetCenter(731 / 4, 731 / 4);
		m_pos.x += (move_speed + 2);
	}
	else if(m_fish==eFish_3)
	{
		m_img.SetSize(800 / 2, 513/ 2);
		m_img.SetCenter(800 / 4, 513 / 4);
		m_pos.x += (move_speed + 1);
	}

}
//更新
void Fish::Update()
{
	m_img.UpdateAnimation();
	if (m_pos.x < 0)
	{
		Kill();
	}
	if (m_pos.x > 1920) 
	{
		Kill();
	}


}
//描画
void Fish::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
//衝突判定
void Fish::Collision(Task* b)
{

}