#include"Player.h"
#include"Field.h"
#include"Task.h"
#include"TaskManager.h"
#include"ObjectBase.h"
//#include"Fish.h"


TexAnim Idle[] = {
{0,6},{1,6},{2,6},{3,6}
};

extern TexAnimData player_anim_data[] = {
	{Idle,sizeof(Idle)/sizeof(Idle[0])}, 
};

Player::Player() : ObjectBase(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	//m_pos = p;
	m_img.ChangeAnimation(0);
	m_img.SetSize(512 / 2, 512 / 2);
	m_is_ground = true;
	m_attack_no = rand();
	m_rad = 100;
	m_rect = CRect(-300, -300, 300, 300);
	m_pos.x = 200;
	m_pos.y = 200;
}

void Player::Move() {
	
	//移動フラグ
	bool isMove = false;
	//移動スピード
	int move_speed = 4;
	//ジャンプ力
	const float jump_pow=15;         
	//左向きの移動(A)
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//右向きの移動(D)
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//Z軸（右斜め上）(W)
	if (HOLD(CInput::eButton1)) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//Z軸（左斜め下）(S)
	else if (HOLD(CInput::eButton3)) {
		m_pos.z -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	
	//ジャンプ(スペース)
	if (m_is_ground && PUSH(CInput::eButton5)) 
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;;
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
	if (PUSH(CInput::eButton6)) {
		Attack();
		m_attack_no++;
	}
}

void Player::Attack()
{
	
}

void Player::Update()
{	
	Move();
	Attack();
	m_img.SetCenter(512 / 4, 512 / 4);

	m_img.UpdateAnimation();
	/*if (m_is_ground && m_vec.y>GRAVITY)
		m_is_ground = false;
		m_vec.y += GRAVITY;
		m_pos += m_vec;
	*/
}

void Player::Render()
{
	DrawRect();
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Player::Collision(Task* b)
{
	switch (b->m_type) 
	{	
		
	case eType_Enemy:
		if (CollisionRect(this, dynamic_cast<ObjectBase*>(b)))
		{

		}
	}
}
