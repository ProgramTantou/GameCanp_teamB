#include"Fish.h"

//�A�j���[�V����
static TexAnim fish[] = {
{0,6},{1,6},{2,6},{3,6}
};
 TexAnimData fish_anim_data[] = {
	{fish,sizeof(fish) / sizeof(fish[0])},
};
//�R���X�g���N�^
Fish::Fish(const CVector3D& pos,int fish) :ObjectBase(eType_Fish) 
{
	m_fish = fish;
	switch (m_fish) 
	{
	case eFish_1:
		m_img.Load("Image/unagi.png",fish_anim_data , 512,512 );
		break;
	case eFish_2:
		m_img.Load("Image/tako.png",fish_anim_data,512 ,512 );
		break;
	case eFish_3:
		m_img.Load("Image/fugu.png",fish_anim_data,512 ,512 );
		break;
	}
	m_pos = pos;
	m_img.ChangeAnimation(0, true);
	m_img.SetSize(512 / 2, 512 / 2);
	m_img.SetCenter(512 / 4, 512 / 4);
	int move_speed = 3;
	if (m_fish == eFish_1) 
	{
		m_pos.x += (move_speed + 3);
	}
	else if (m_fish == eFish_2) 
	{
		m_pos.x += (move_speed + 2);
	}
	else if(m_fish==eFish_3)
	{
		m_pos.x += (move_speed + 1);
	}

}
//�X�V
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
//�`��
void Fish::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
//�Փ˔���
void Fish::Collision(Task* b)
{

}