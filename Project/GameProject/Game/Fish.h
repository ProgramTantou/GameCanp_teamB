#pragma once
#include"ObjectBase.h"

class Fish :public ObjectBase {
private:
	CImage m_img;
public:
	Fish(const CVector3D& pos,int fish);
	//‹›‚Ìí—Ş
	int m_fish;
	//XV
	void Update() override;
	//•`‰æ
	void Render() override;
	//Õ“Ë”»’è
	void Collision(Task* b) override;
};