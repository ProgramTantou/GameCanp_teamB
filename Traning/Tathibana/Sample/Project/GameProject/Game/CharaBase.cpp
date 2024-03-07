#include"CharaBase.h"
//コンストラクタ
CharaBase::CharaBase(const CVector2D& pos) :ObjectBase(pos), m_hp(100), m_isDeath(false) {

}
//デストラクタ
CharaBase::~CharaBase() {

}
//ダメージを受ける
void CharaBase::TakeDamege(int damage) {

    //すでにHPが０なら、ダメージ処理を実行しない
	if (m_hp <= 0)
	{
		return;
	}
	m_hp -= damage;

	if (m_hp <= 0) {
		Death();
	}
}

//死亡したときの処理
void CharaBase::Death() {
	m_isDeath = true;
}