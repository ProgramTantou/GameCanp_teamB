#pragma once

class Player
{

	//�������g�̊O������A�N�Z�X�\
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	void Update();

	void Render();
	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	/// <returns>�v���C���[�̍��W���擾</returns>
	const CVector2D& GetPos();

	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(CVector2D& pos);

	void GetStatus(int* hp, int* atk);
	//�A�N�Z�X�C���q
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ��B
private:
	CVector2D m_pos;//�v���C���[�̍��W
	TexAnimData* mp_anim;
	CImage* mp_image;//�v���C���[�̉摜
	int m_hp;
	//�����Ǝ��N���X���p�������N���X����A�N�Z�X�\
};