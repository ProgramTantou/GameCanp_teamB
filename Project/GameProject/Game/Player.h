#pragma once
#include"../Base/Base.h"

extern TexAnimData player_anim_data[];
class Player :public Base {
private:
	CImage m_img;
	//地面に足がついているかのフラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
	//反転フラグ
	bool m_flip;
	//int m_damage_no;
	//HP残量
	static int m_hp;

public:
	Player(const CVector3D& p,bool flip);
	
	// CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	 static int GetHp();
	//更新
	void Update();
	//移動
	void Move();
	//ダメージ
	void Damage();
	//攻撃
	void Attack();
	//描画
	void Draw();
	//衝突処理
	void Collision(Base* b);
	

};
