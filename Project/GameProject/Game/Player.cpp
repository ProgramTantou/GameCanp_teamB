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
	
	//�ړ��t���O
	bool isMove = false;
	//�ړ��X�s�[�h
	int move_speed = 2;
	//�W�����v��
	const float jump_pow=15;         
	//�������̈ړ�
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//�E�����̈ړ�
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//Z���i�E�΂ߏ�j
	if (HOLD(CInput::eButton1)) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	//Z���i���΂߉��j
	else if (HOLD(CInput::eButton3)) {
		m_pos.z -= move_speed;
		m_img.ChangeAnimation(0);
		isMove = true;
	}
	
	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton5)) 
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	//�W�����v��
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸
			m_img.ChangeAnimation(0);
		else
			//���~
			m_img.ChangeAnimation(0);
	}
	//�n�ʂɒ����Ă���
	else 
	{
		if (isMove) 
		{
			//�ړ�
			m_img.ChangeAnimation(0);
		}
		else 
		{
			//�ҋ@
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
