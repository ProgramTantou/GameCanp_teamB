#pragma once
#include "CharaBase.h"

class Player :public CharaBase
{
//�A�N�Z�X�C���q
//�����ȊO�̊O������A�N�Z�X������
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//���S�����Ƃ��̏���
	void Death() override;

	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;

//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
//�����o�ϐ��͊�{private
private:
	TexAnimData* mp_animData;    //�A�j���[�V�����̃f�[�^
	CImage* mp_image;    //�v���C���[�̉摜
	//int m_hp;            //�Ղꂢ��[��HP


//�����Ǝ��N���X�̌p�������N���X�ŃA�N�Z�X�ł���
protected:

};