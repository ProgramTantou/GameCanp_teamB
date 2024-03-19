#include "Boss.h"
#include "Fish.h"
#include "Player.h"
#include "GameData.h"
#include "EnemyAttack.h"
#include "TaskManager.h"


Boss::Boss(const CVector3D& pos, bool flip) :ObjectBase(eType_Enemy) {
	m_pos = pos;
	m_flip = flip;
	m_img = COPY_RESOURCE("Boss", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(512, 512);
	m_img.SetCenter(256, 256);
	m_rect = CRect3D(-256, -256, 256, 256,256,-256);
	m_hp = 7;
	Timer = 0;
	attack_Timer = 0.0f;
	attack_Interval = 60.0f;
}

int Boss::GetHP() 
{
	return m_hp;
}

void Boss::GiveScore(int Score)
{
	GameData::m_score += Score;
}

void Boss::Dead() {
	Kill();
}

void Boss::Update()
{
	const float Boss_Speed = 3;

	//アニメーションの変更
	m_img.ChangeAnimation(move_dir);
	//アニメーションの更新
	m_img.UpdateAnimation();
}

void Boss::Render()
{
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//DrawRect();
}

void Boss::Attack()
{
	Task* p = TaskManager::FindObject(eType_Player);
}

void Boss::Collision(Task* b) 
{
	if (Fish* f = dynamic_cast<Fish*>(b))
	{
		if (m_Damage_no != f->GetAttackNo() && ObjectBase::CollisionRect(this, f))
		{
			m_Damage_no = f->GetAttackNo();
			m_hp -= 1;
			if (m_hp <= 0)
			{
			//	Dead();
				GiveScore(500);
			}
		}
	}
}

