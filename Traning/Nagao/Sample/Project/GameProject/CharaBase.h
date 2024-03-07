#pragma once
#include "ObjectBase.h"

class CharaBase : public ObjectBase
{
public:	///

	CharaBase(const CVector2D& pos);
	virtual ~CharaBase();
	void TakeDamage(int damage);
	virtual void Death();

protected:
	int m_hp;
	bool m_is_Death;
		
};