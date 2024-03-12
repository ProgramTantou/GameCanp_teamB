#pragma once
#include"ObjectBase.h"

class Fish :public ObjectBase {
private:
	CImage m_img;
public:
	Fish(const CVector3D& pos,int fish);
	//���̎��
	int m_fish;
	//�X�V
	void Update() override;
	//�`��
	void Render() override;
	//�Փ˔���
	void Collision(Task* b) override;
};