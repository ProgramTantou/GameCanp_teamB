#pragma once
#include"../Base/Base.h"

extern TexAnimData player_anim_data[];
class Player :public Base {
private:
	CImage m_img;
	




public:
	Player(const CVector3D& p );
	
	//const CVector2D& GetPos()const;

	//void SetPos(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);

};
