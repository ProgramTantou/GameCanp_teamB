#pragma once
#include"ObjectBase.h"

//魚のアニメーションデータ
extern TexAnimData fish_anim_data[];

class Fish :public ObjectBase {
private:
	enum {
		eMove,
		eAttack,
		eDown,
	};
	CImage m_img;
	Task* player;
	int cnt;
	int time;
	bool m_flip;
	bool m_screen;
	int m_attack_no;
	int move_speed;
public:
	Fish(const CVector3D& pos,Task*b, int fish, bool flip, int attack_no,int type);
	//魚の種類
	int m_fish;
	//更新
	void Update() override;
	int GetAttackNo()
	{
		return m_attack_no;
	}
	//描画
	void Render() override;
	//衝突判定
	void Collision(Task* b) override;
};