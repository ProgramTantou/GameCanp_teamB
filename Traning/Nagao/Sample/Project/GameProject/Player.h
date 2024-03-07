#pragma once
#include "ObjectBase.h"
#include "CharaBase.h"

class Player : public CharaBase
{

	//�������g�̊O������A�N�Z�X�\
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//���S�����Ƃ��̏���

	void Update() override;

	void Death() override;

	void Render() override;
	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	
	//�A�N�Z�X�C���q
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ��B
private:
	TexAnimData* mp_anim;
	CImage* mp_image;//�v���C���[�̉摜
	//�����Ǝ��N���X���p�������N���X����A�N�Z�X�\
};