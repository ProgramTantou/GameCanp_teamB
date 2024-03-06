#include"Player.h"
#include"Field.h"
//#include"Fish.h"


TexAnim Idle[] = {
{0,6},{1,6},{2,6},{3,6}
};

extern TexAnimData player_anim_data[] = {
	{Idle,sizeof(Idle)/sizeof(Idle[0])}, 
};

Player::Player(const CVector3D& p) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = p;
	m_img.ChangeAnimation(0);
	m_is_ground = true;
}

void Player::Move() {
	
	//移動フラグ
	bool isMove = false;
	//移動スピード
	int move_speed = 2;
	//ジャンプ力
	const float jump_pow=15;         
	//左向きの移動
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//右向きの移動
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//Z軸（右斜め上）
	if (HOLD(CInput::eButton1)) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//Z軸（左斜め下）
	else if (HOLD(CInput::eButton3)) {
		m_pos.z -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton5)) 
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//ジャンプ中
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇
			m_img.ChangeAnimation(0);
		else
			//下降
			m_img.ChangeAnimation(0);
	}
	//地面に着いている
	else 
	{
		if (isMove) 
		{
			//移動
			m_img.ChangeAnimation(0);
		}
		else 
		{
			//待機
			m_img.ChangeAnimation(0);
		}
	}
}

void Player::Attack() {

}

void Player::Update()
{	
	Move();
	Attack();

	m_img.UpdateAnimation();
	if (m_is_ground&&m_vec.y>GRAVITY) 
		m_is_ground = false;
		m_vec.y += GRAVITY;
		m_pos += m_vec;
}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Player::Collision(Base* b)
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
	}
}
