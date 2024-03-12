#pragma once
#include"../Base/Base.h"

class EnemyAttack : public Base {
public:
	//コンストラクタ
	EnemyAttack(const CVector3D& pos, const int attack_no, int attack, bool flip);
	//更新メソッド
	void Update();
	//描画メソッド
	void Draw();
	//ダメージを取得
	int GetDamage()const;
	
	int GettAttackNo() 
	{
		return m_attack_no;
	}
private:
	CImage m_img;
	int m_damage;//攻撃のダメージ
	float m_rot; //攻撃の向き
	int m_attack_no;//攻撃番号
	int m_timeout;//敵の攻撃が消えるまでの時間
	bool m_flip;

};