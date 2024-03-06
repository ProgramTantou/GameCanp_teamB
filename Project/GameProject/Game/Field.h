#pragma once
class Field {
public:
	//�R���X�g���N�^
	Field();
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
	void Update();
	//�`�揈��
	void Draw();

	/// <summary>
	/// �t�B�[���h�̍������擾
	/// </summary>
	/// <returns>�t�B�[���h�̍���</returns>
	const float GetGroundY();

private:
	CVector2D m_pos;  //�t�B�[���h�̍��W
	CImage* mp_image; //�t�B�[���h�̉摜
	float m_ground_y; //�t�B�[���h�̓����蔻��

protected:

};
