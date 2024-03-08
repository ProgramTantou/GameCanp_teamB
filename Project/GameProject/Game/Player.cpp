#include"Player.h"
#include"Field.h"
#include"Fish.h"
#include"Enemy.h"

//�A�j���[�V����
TexAnim Idle[] = {
{0,6},{1,6},{2,6},{3,6}
};
extern TexAnimData player_anim_data[] = {
	{Idle,sizeof(Idle)/sizeof(Idle[0])}, 
};

int Player::m_hp;
//�R���X�g���N�^
Player::Player(const CVector3D& p,bool flip) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = p;
	m_img.ChangeAnimation(0);
	m_img.SetSize(512 / 2, 512 / 2);
	m_img.SetCenter(256/2, 256/1);
	m_img.SetRect(-512/4, -512/2, 512/4, 0);
	m_rect = CRect(-512/4, -512/2, 512/4, 0);
	m_flip = flip;
	m_is_ground = true;
	m_attack_no = rand();
	m_hp = 9;
}
//�ړ�
void Player::Move() {
	
	//�ړ��t���O
	bool isMove = false;
	//�ړ��X�s�[�h
	int move_speed = 4;
	/*if (Damage)
	{
		move_speed = move_speed / 2;
	}*/
	//�W�����v��
	const float jump_pow=15;         
	//�������̈ړ�(A)
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_img.ChangeAnimation(0);
		m_flip = true;
		isMove = true;
	}
	//�E�����̈ړ�(D)
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		m_img.ChangeAnimation(0);
		m_flip = false;
		isMove = true;
	}
	//Z���i�E�΂ߏ�j(W)
	if (HOLD(CInput::eButton1)&&m_pos.z<50) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		m_flip = false;
		isMove = true; 
	}
	//Z���i���΂߉��j(S)
	else if (HOLD(CInput::eButton3)&&m_pos.z>-370) {
		m_pos.z -= move_speed;
		m_img.ChangeAnimation(0);
		m_flip = true;
		isMove = true;
	}
	
	//�W�����v(�X�y�[�X)
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
	if (PUSH(CInput::eButton6)) {
		Attack();
		m_attack_no++;
	}
	Damage();
}

//�U�����󂯂��ۂ̓_�ŕ\��
void Player::Damage()
{

}
//�U��
void Player::Attack() {
	//C�L�[
	if (PUSH(CInput::eButton6)) {
		Base::Add(new Fish(CVector2D (GetScreenPos(m_pos)), 1));
	}
	//V�L�[
	else if (PUSH(CInput::eButton7)) 
	{
		Base::Add(new Fish(CVector2D(GetScreenPos(m_pos)), 2));
	}
	//B�L�[
	else if (PUSH(CInput::eButton8)) 
	{
		Base::Add(new Fish(CVector2D(GetScreenPos(m_pos)), 3));
	}
	
}
//
int Player::GetHp()
{
	return m_hp;
}

//�X�V
void Player::Update()
{	
	Move();
	m_img.UpdateAnimation();
	if (m_is_ground&&m_vec.y>GRAVITY*4) 
	{
		m_is_ground = false;
		m_vec.y += GRAVITY;
		m_pos += m_vec;
	}
		m_scroll.x = m_pos.x - 1920 / 2;
	
}
//�`��
void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	DrawRect();
}
//�Փ˔���
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
	case eType_Enemy_Attack:
		

		break;
	}
}
