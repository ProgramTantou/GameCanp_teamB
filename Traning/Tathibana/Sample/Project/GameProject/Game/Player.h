#pragma once
#include"CharaBase.h"
class Player :public CharaBase 
{
	//�A�N�Z�X�C���q
	//�����ȊO�ɊO������A�N�Z�X������
public:
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
	//�����o�ϐ��͊�{private
	
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();
	//���S����
	void Death() override;
	
	//�p����ObjectBase�E�p����Player
	//�錾���E�E�p����virtual�i�O�j�E�p����override(���j
	
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render();
private:
	//�����Ǝ��N���X���p�������N���X�ŃA�N�Z�X�ł���
	
	TexAnimData* mp_animData;	//�v���C���[�̃A�j���\�V����
	CImage* mp_image;			//�v���C���[�̉摜
					
protected:
};