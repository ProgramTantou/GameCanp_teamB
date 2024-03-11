#include"Player.h"
#include"Field.h"
#include"Fish.h"
#include"Enemy.h"
#include"GameData.h"

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
	m_rect = CRect(-512/6, -512/2, 512/6, 0);
	m_flip = flip;
	m_state = eState_Move;
	m_is_ground = true;
	m_attack_no = rand();
	m_damage_no = rand();
	//damage_count = 0;
	m_damage = 0;
	m_draw_count = 1;
	m_hp = 9;
	move_speed = 6;
	jump_pow = 12;
}
//移動
void Player::Move() {
	
	//移動フラグ
	bool isMove = false;
	//移動スピード
	move_speed = 6;
	//ジャンプ力
	jump_pow=12;  
	//攻撃を受けたら減速
	if (m_damage > 0) {
		move_speed = move_speed / 2;
		jump_pow = jump_pow / 2;
		m_damage--;
	}
	
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
	if (HOLD(CInput::eButton1)&&m_pos.z<80) {
		m_pos.z += move_speed;
		m_img.ChangeAnimation(0);
		m_flip = false;
		isMove = true; 
	}
	//Z軸（左斜め下）(S)
	else if (HOLD(CInput::eButton3)&&m_pos.z>-280) {
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
		m_state=eState_Attack;
		m_attack_no++;
	}
	else if (PUSH(CInput::eButton7)) 
	{
		m_state=eState_Attack;
		m_attack_no++;
	}
	else if (PUSH(CInput::eButton8)) 
	{
		m_state=eState_Attack;
		m_attack_no++;
	}
	if (PUSH(CInput::eMouseL))
	{
		if (m_hp > 0) {
			m_state = eState_Damage;
		}
		else if (m_hp == 0)
		{
			m_state = eState_Down;
		}
		
		
	}
}
//攻撃
void Player::Attack() {
	m_img.ChangeAnimation(0);
	//Cキー
	if (PUSH(CInput::eButton6))
	{
		Base::Add(new Fish(CVector2D (GetScreenPos(m_pos)), 1));
		m_state = eState_Move;
	}
	//Vキー
	else if (PUSH(CInput::eButton7)) 
	{
		Base::Add(new Fish(CVector2D(GetScreenPos(m_pos)), 2));
		m_state = eState_Move;
	}
	//Bキー
	else if (PUSH(CInput::eButton8)) 
	{
		Base::Add(new Fish(CVector2D(GetScreenPos(m_pos)), 3));
		m_state = eState_Move;
	}
	
	/*if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}*/
}
//ダメージ
void Player::Damage()
{
	m_hp--;
	m_img.ChangeAnimation(0);
	m_damage = 60 * 3;
	
	// = false;
	/*if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Move;
	}*/
	m_state = eState_Move;
}
//死亡
void Player::Down()
{
	m_img.ChangeAnimation(0);
	if (m_img.CheckAnimationEnd())
	{
		m_kill = true;
		GameData::death_flag = true;
	}
	
}

int Player::GetHp()
{
	return m_hp;
}

//更新
void Player::Update()
{
	//m_pos_old = m_pos;
	switch (m_state) 
	{
	case eState_Move:
		Move(); 
		break;
	case eState_Attack:
		Attack();
		break;
	case eState_Damage:
		Damage();
		break;
	case eState_Down:
		Down();
		break;
	}
	m_img.UpdateAnimation();
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_scroll.x = m_pos.x - 1920 / 2;

}
//描画
void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);

		
		
	
	if(m_damage%8==0)
		m_img.Draw();
	
	
	//DrawRect();
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
