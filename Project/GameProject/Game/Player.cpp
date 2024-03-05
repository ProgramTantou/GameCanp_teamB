#include"Player.h"
TexAnim Idle[] = {
{0,6},
};

extern TexAnimData player_anim_data[] = {
	{Idle,sizeof(Idle)/sizeof(Idle[0])}, 
};

Player::Player(const CVector3D& p) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = p;
	m_img.ChangeAnimation(0);
}

void Player::Update()
{
	m_img.UpdateAnimation();
}

void Player::Draw()
{
	m_img.Draw();
}

void Player::Collision(Base* b)
{
}
