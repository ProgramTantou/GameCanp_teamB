#pragma once
#include "CharaBase.h"
class Player : public CharaBase{
//�A�N�Z�X�C���q
//�����ȊO�̃N���X����A�N�Z�X������
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//���S�������̏���
	void Death() override;

	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;

//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
//�����o�ϐ��͊�{private
private:
	
	TexAnimData* mp_animData; //�A�j���[�V�����̃f�[�^
	CImage* mp_image; //�v���C���[�̉摜

//�����Ǝ��N���X���p�������N���X�ŃA�N�Z�X�ł���
protected:

};

