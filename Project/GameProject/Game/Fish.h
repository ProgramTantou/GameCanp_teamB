#pragma once
#include"ObjectBase.h"

extern TexAnimData fish_anim_data[];

class Fish :public ObjectBase {
private:
	CImage m_img;
	int cnt;
	bool m_flip;
	int m_attack_no;
public:
	Fish(const CVector3D& pos,int fish,bool flip);
	//���̎��
	int m_fish;
	//�X�V
	void Update() override;
	int GetAttackNo()
	{
		return m_attack_no;
	}
	//�`��
	void Render() override;
	//�Փ˔���
	void Collision(Task* b) override;
};