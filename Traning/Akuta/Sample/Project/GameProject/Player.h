#pragma once

class Player
{
//�A�N�Z�X�C���q
//�����ȊO�̊O������A�N�Z�X������
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	/// <summary>
	/// �v���C���[�̍��W���擾
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	const CVector2D& GetPos() const;

	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷��l</param>
	void SetPos(const CVector2D& pos);

	//�X�V����
	void Update();
	//�`�揈��
	void Render();

//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
//�����o�ϐ��͊�{private
private:
	CVector2D m_pos;     //�v���C���[�̍��W
	TexAnimData* mp_animData;    //�A�j���[�V�����̃f�[�^
	CImage* mp_image;    //�v���C���[�̉摜
	int m_hp;            //�Ղꂢ��[��HP


//�����Ǝ��N���X�̌p�������N���X�ŃA�N�Z�X�ł���
protected:

};