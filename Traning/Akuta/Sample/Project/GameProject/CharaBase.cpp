#include "CharaBase.h"

//コンストラクタ
CharaBase::CharaBase(const CVector2D& pos)
	:ObjectBase(pos)
	,m_hp(100)
	,m_isDeath(false)
{

}

//デストラクタ
CharaBase::~CharaBase()
{

}

//ダメージを受ける
void CharaBase::TakeDamage(int damage)
{
	//すでにHPが0であれば、ダメージ処理を実行しない
	if (m_hp <= 0)return;

	//のこりHPからダメージ分減算
	m_hp -= damage;
	//のこりHP が0であれば
	if (m_hp <= 0) 
	{
		//死亡処理
		Death();
	}
}

//死亡したときの処理
void CharaBase::Death()
{
	m_isDeath = true;
}