#include"Player.h"
#include"Field.h"
#include"Fish.h"
#include"Enemy.h"

//アニメーション
TexAnim Idle[] = {
{0,6},{1,6},{2,6},{3,6}
};
extern TexAnimData player_anim_data[] = {
	{Idle,sizeof(Idle)/sizeof(Idle[0])}, 
};

int Player::m_hp;
//コンストラクタ
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
//移動
void Player::Move() {
	
	//移動フラグ
	bool isMove = false;
	//移動スピード
	int move_speed = 4;
	/*if (Damage)
	{
		move_speed = move_speed / 2;
	}*/
	//ジャンプ力
	const float jump_pow=15;         
	//左向きの移動(A)
	if (HOLD(CInput::eButton2)) {
		m_pos.x -= move_speed;
		m_img.ChangeAnimation(0);
		m_flip = true;
		isMove = true;
	}
	//右向きの移動(D)
	else if (HOLD(CInput::eButton4)) {
		m_pos.x += move_speed;
		m_img.ChangeAnimation(0);
		m_flip = false;
		isMove = true;
	}
	//Z軸（右斜め上）(W)
	if (HOLD(CInput::eButton1)&&m_pos.z<50) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		m_flip = false;
		isMove = true; 
	}
	//Z軸（左斜め下）(S)
	else if (HOLD(CInput::eButton3)&&m_pos.z>-370) {
		m_pos.z -= move_speed;
		m_img.ChangeAnimation(0);
		m_flip = true;
		isMove = true;
	}
	
	//ジャンプ(スペース)
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
	if (PUSH(CInput::eButton6)) {
		Attack();
		m_attack_no++;
	}
	Damage();
}

//攻撃を受けた際の点滅表示
void Player::Damage()
{

}
//攻撃
void Player::Attack() {
	//Cキー
	if (PUSH(CInput::eButton6)) {
		Base::Add(new Fish(CVector2D (GetScreenPos(m_pos)), 1));
	}
	//Vキー
	else if (PUSH(CInput::eButton7)) 
	{
		Base::Add(new Fish(CVector2D(GetScreenPos(m_pos)), 2));
	}
	//Bキー
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

//更新
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
//描画
void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	DrawRect();
}
//衝突判定
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
