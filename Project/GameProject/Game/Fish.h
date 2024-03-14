#pragma once
#include"ObjectBase.h"

extern TexAnimData fish_anim_data[];

class Fish :public ObjectBase {
private:
	CImage m_img;
	int cnt;
	bool m_flip;
public:
	Fish(const CVector3D& pos,int fish,bool flip);
	//‹›‚Ìí—Ş
	int m_fish;
	//XV
	void Update() override;
	//•`‰æ
	void Render() override;
	//Õ“Ë”»’è
	void Collision(Task* b) override;
};