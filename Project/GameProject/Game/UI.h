#pragma once
#include "Base/Base.h"

class UI : public Base {
private:
	//HP�̉摜�f�[�^
	CImage m_img;
	//�������Ă��鋛�̉摜�f�[�^
	CImage m_img2;
	//�X�R�A�\���p�̕����\���I�u�W�F�N�g
	CFont m_UI_text;
	//�摜��`�p�̕ϐ�
	int hp;
	//UI�̔��ʗp�̕ϐ�
	int UI_number;
	//�v���C���[�̃|�C���^�[
	Base* p_player;
public:
	//�R���X�g���N�^
	UI(const CVector3D& pos,int UI_Nunber, Base* b);
	//�f�X�g���N�^
	~UI();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};