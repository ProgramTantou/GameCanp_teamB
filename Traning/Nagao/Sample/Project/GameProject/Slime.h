#pragma once

class Slime
{

	//�������g�̊O������A�N�Z�X�\
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="type">�X���C���̎��</param>
	/// <param name="pos">�����ʒu</param>
	Slime(int type, const CVector2D& pos);
	//�R���X�g���N�^
	const CVector2D& GetPos() const;
	//�f�X�g���N�^
	~Slime();

	void Update();

	void Render();
	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	/// <returns>�v���C���[�̍��W���擾</returns>
	void GetStatus(int* hp, int* atk);

	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(CVector2D pos);
	//�A�N�Z�X�C���q
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ��B
private:
	CVector2D m_pos;//�v���C���[�̍��W
	TexAnimData* mp_anim;
	CImage* mp_image;//�v���C���[�̉摜
	int m_hp;
	int m_type;
	//�����Ǝ��N���X���p�������N���X����A�N�Z�X�\
};