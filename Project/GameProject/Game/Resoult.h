#pragma once
#include "ObjectBase.h"
#include "TaskManager.h"

class Resoult : public ObjectBase
{
private:
	CImage m_img; //�摜�I�u�W�F�N�g
	CFont m_font; //�����I�u�W�F�N�g��
	CFont m_font2; //�����I�u�W�F�N�g��
	int coro = 0; //1�ŃQ�[���I�[�o�[�A2�ŃQ�[���N���A

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="CorO">�Q�[���I�[�o�[���Q�[���N���A��</param>
	Resoult(int CorO);
	//�f�X�g���N�^
	~Resoult();
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;
};