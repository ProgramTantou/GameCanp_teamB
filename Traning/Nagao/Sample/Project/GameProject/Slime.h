#pragma once
#include "CharaBase.h"

class Slime : public CharaBase
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

	void Update() override;

	void Render() override;
	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	/// <returns>�v���C���[�̍��W���擾</returns>

	/// <summary>
	/// �v���C���[�̍��W������
	/// </summary>
	/// <param name="pos"></param>
	//�A�N�Z�X�C���q
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ��B
private:
	TexAnimData* mp_anim;
	CImage* mp_image;//�v���C���[�̉摜
	int m_type;
	//�����Ǝ��N���X���p�������N���X����A�N�Z�X�\
};