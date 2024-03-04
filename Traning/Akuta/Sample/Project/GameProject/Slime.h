#pragma once

class Slime
{
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
	/// ���W���擾
	/// </summary>
	/// <returns>���W</returns>
	const CVector2D& GetPos() const;

	/// <summary>
	/// ���W��ݒ�
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
	CVector2D m_pos;     //���W
	TexAnimData* mp_animData;    //�A�j���[�V�����̃f�[�^
	CImage* mp_image;    //�摜
	int m_hp;            //HP
	int m_type;			//�X���C���̎��

};