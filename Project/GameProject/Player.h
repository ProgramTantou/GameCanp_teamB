#pragma once
class Player{
//�A�N�Z�X�C���q
//�����ȊO�̃N���X����A�N�Z�X������
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	/// <summary>
	/// �v���C���[�̍��W���擾
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	CVector2D GetPos();

	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(CVector2D pos);

//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
//�����o�ϐ��͊�{private
private:
	CVector2D m_pos; //�v���C���[�̍��W
	TexAnimData* mp_animData; //�A�j���[�V�����̃f�[�^
	CImage* mp_image; //�v���C���[�̉摜
	int m_hp; //�v���C���[��HP

//�����Ǝ��N���X���p�������N���X�ŃA�N�Z�X�ł���
protected:

};
