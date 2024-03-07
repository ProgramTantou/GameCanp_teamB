#pragma once
#include"CharaBase.h"

class Slime:public CharaBase
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


	//�X�V����
	void Update()override;
	//�`�揈��
	void Render()override;
private:
	//�����Ǝ��N���X���p�������N���X�ŃA�N�Z�X�ł���
	
	TexAnimData* mp_animData;	//�A�j���\�V����
	CImage* mp_image;			//�摜	
	int m_type;					//�X���C���̎��





};