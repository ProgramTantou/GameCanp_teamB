#pragma once
#include"Base/Base.h"

class Fish :public Base {
private:
	CImage m_img;
public:
	Fish(const CVector2D& pos,int fish);
	//���̎��
	int m_fish;
	//�X�V
	void Update();
	//�`��
	void Draw();
	//�Փ˔���
	void Collision(Base* b);
};