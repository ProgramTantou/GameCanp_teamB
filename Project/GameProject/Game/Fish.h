#pragma once
#include"ObjectBase.h"



class Fish :public ObjectBase {
private:
	enum {
		e_Move,
		e_Attack,
		e_Down
	};
	int m_State;
	
	CImage m_img;
	Task* player;
	int cnt;
	int time;
	bool m_flip;
	bool m_screen;
	int m_attack_no;
	int move_speed;
public:
	Fish(const CVector3D& pos,Task*b, int fish, bool flip, int attack_no,int type);
	//���̎��
	int m_fish;
	//�ړ�
	void Move();
	//�U��
	void Attack();
	//��
	void Down();
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