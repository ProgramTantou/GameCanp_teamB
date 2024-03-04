#pragma once
class Slime {
	//�A�N�Z�X�C���q
	//�����ȊO�̃N���X����A�N�Z�X������
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="type">�X���C���̎��</param>
	/// <param name="pos">�����ʒu</param>
	Slime(int type, const CVector2D& pos);
	//�f�X�g���N�^
	~Slime();

	/// <summary>
	/// �v���C���[�̍��W���擾
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	const CVector2D& GetPos() const ;

	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(const CVector2D& pos);

	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
	//�����o�ϐ��͊�{private
private:
	CVector2D m_pos; //�v���C���[�̍��W
	TexAnimData* mp_animData; //�A�j���[�V�����̃f�[�^
	CImage* mp_image; //�v���C���[�̉摜
	int m_hp; //�v���C���[��HP
	int m_type; //�X���C���̎��

//�����Ǝ��N���X���p�������N���X�ŃA�N�Z�X�ł���
protected:

};


