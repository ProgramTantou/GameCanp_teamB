#pragma once
#include "ObjectBase.h"

class CharaBase : public ObjectBase
{
public:
	CharaBase(const CVector2D& pos,int type);
	virtual ~CharaBase();
	void TakeDamage(int damage);
	virtual void Death();
	CRect m_rect;

protected:
	int m_hp;
	bool m_is_Death;


};