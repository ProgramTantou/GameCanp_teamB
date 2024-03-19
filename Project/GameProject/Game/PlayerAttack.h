#pragma once
#include"ObjectBase.h"

class PlayerAttack :public ObjectBase 
{
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;
public:
	PlayerAttack(const CVector3D& pos, bool flip, int attack_no);
	void Update();
	void Render();
	int GetAttackNo() {
		return m_attack_no;
	}
	
};