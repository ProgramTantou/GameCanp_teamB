#pragma once
#include "ObjectBase.h"

extern TexAnimData player_anim_data[];
class Player :public ObjectBase{
private:
	CImage m_img;
	//地面に足がついているかのフラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
	//反転フラグ
	bool m_flip;
	int m_damage_no;
	//HP残量
	static int m_hp;
	bool damage;
	int i;
	
	//ダメージ受けた際の表示時間
	int damage_count;
	//攻撃を受けた時のフラグ
	
	int m_damage;
	int m_draw_count;
	int move_speed;
	int jump_pow;
	int m_state;

	enum {
		eState_Move,
		eState_Attack,
		eState_Damage,
		eState_Down
	};
	//移動
	void Move();
	//ダメージ
	void Damage();
	//攻撃
	void Attack();
	//死
	void Down();


public:
	Player(const CVector3D& p,bool flip);
	
	// CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	 static int GetHp();
	//更新
	void Update() override;
	
	//描画
	void Render() override;
	//衝突処理
	void Collision(Task* b) override;
	//最大HP
	static int m_maxhp;

};
