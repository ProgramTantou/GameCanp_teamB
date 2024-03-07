#pragma once
#include"Game/ObjectBase.h"

class CharaBase :public ObjectBase {
public:
	CharaBase(const CVector2D& pos);
		virtual  ~CharaBase();
	void TakeDamege(int damaga);
	virtual void Death();
protected:
	int m_hp;
	bool m_isDeath;
};