#pragma once
class Slime
{
	//�A�N�Z�X�C���q
	//�����ȊO�ɊO������A�N�Z�X������
public:
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
	//�����o�ϐ��͊�{private
	

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="type">�X���C���̎��</param>
	/// <param name="pos">�����ʒu</param>
	Slime(int type ,const CVector2D& pos);
	//�f�X�g���N�^
	~Slime();



	/// <summary>
	/// �v���C���[�̍��W���擾
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	const CVector2D& GetPos()const;
	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D& pos);

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
	int m_type;





};