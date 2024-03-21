#pragma once
#include "Task.h"
#include "TaskManager.h"
#include "ObjectBase.h"

class Field : public Task {
public:
	//�R���X�g���N�^
	Field(int Field_Nunber);
	//�f�X�g���N�^
	~Field();

	/// <summary>
	/// �t�B�[���h�̍��W��ݒ�
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(const CVector2D& pos);

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
