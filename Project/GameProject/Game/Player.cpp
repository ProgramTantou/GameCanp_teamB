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

void Player::Move() {
	
	bool isMove = false;
	int move_speed = 2;
	//
	/*if (HOLD(CInput::eButton1)) {
		m_pos.y += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//
	else if (HOLD(CInput::eButton3)) {
		m_pos.y -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}*/
	//A
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//D
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	if (HOLD(CInput::eUp)) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	else if (HOLD(CInput::eDown)) {
		m_pos.z -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}

}

void Player::Update()
{	
	Move();
	m_img.UpdateAnimation();
}


void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Player::Collision(Base* b)
{
}
