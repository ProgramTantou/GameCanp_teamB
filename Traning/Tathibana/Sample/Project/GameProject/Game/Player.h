#pragma once

class Player 
{
	//�A�N�Z�X�C���q
	//�����ȊO�ɊO������A�N�Z�X������
public:
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
	//�����o�ϐ��͊�{private
	
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();



	/// <summary>
	/// �v���C���[�̍��W���擾
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	const CVector2D& GetPos()const;
	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D &pos);

	//�X�V����
	void Update();
	//�`�揈��
	void Render();
private:
	//�����Ǝ��N���X���p�������N���X�ŃA�N�Z�X�ł���
	CVector2D m_pos;			//�v���C���[�̍��W
	TexAnimData* mp_animData;	//�v���C���[�̃A�j���\�V����
	CImage* mp_image;			//�v���C���[�̉摜
	int m_hp;					//�v���C���[��HP
protected:
};