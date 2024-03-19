#pragma once
#include "Task.h"
#include "ObjectBase.h"

class Field : public Task {
public:
	//�R���X�g���N�^
	Field(int Field_Nunber);
	//�f�X�g���N�^
	~Field();

	/// <summary>
	/// �t�B�[���h�̍��W���擾
	/// </summary>
	/// <returns>�t�B�[���h�̍��W</returns>
	//const CVector2D& GetPos() const;

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

	static int Stage_number; //�X�e�[�W�̔��ʗp�̕ϐ�
private:
	CVector2D m_pos;  //�t�B�[���h�̍��W
	CImage mp_image; //�t�B�[���h�̉摜
	float m_ground_y; //�t�B�[���h�̓����蔻��
	int Field_number; //�t�B�[���h�̎�ޔ��ʗp�ϐ�

protected:

};
