#pragma once
#include "ObjectBase.h"

class MostFront : public ObjectBase {
public:
	//���I�u�W�F�N�g�̉摜�f�[�^
	CImage mp_image_Light;
	//�����I�u�W�F�N�g�̉摜�f�[�^
	CImage mp_image_Underwater;
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="Field_Number">�\���摜�̕���</param>
	MostFront(int Field_Number);
private:
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;
	//�ǂݍ��݉摜����p�̕ϐ�
	int Field_number;
	//�����̕\���p�ϐ�
	int count;
	//���̕\���p�ϐ�
	int count2;
};
