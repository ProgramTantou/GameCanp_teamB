#pragma once
#include "Task.h"
#include "TaskManager.h"
#include "ObjectBase.h"

class Field : public Task {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="Field_Nunber">�t�B�[���h�摜�̕���</param>
	Field(int Field_Nunber);
	//�f�X�g���N�^
	~Field();
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;

	/// <summary>
	/// �t�B�[���h�̍������擾
	/// </summary>
	/// <returns>�t�B�[���h�̍���</returns>
	const float GetGroundY();

	static bool Next_flag; //���̃X�e�[�W�ɍs���邩�̔���p�t���O
private:
	CVector2D m_pos;  //�t�B�[���h�̍��W
	CImage mp_image_Back; //�w�i�̉摜
	CImage mp_image_Field; //�t�B�[���h�̉摜
	CImage mp_image_Pillar; //���̉摜
	float m_ground_y; //�t�B�[���h�̓����蔻��
	int Field_number; //�t�B�[���h�̎�ޔ��ʗp�ϐ�
	int Stage_number = 1; //�X�e�[�W�̔��ʗp�̕ϐ�
	int Enemy_pos_Control; //�G�̈ʒu����p�̕ϐ�
protected:

};
