#pragma once
#include "Task.h"

class UI : public Task {
private:
	//HP�̉摜�f�[�^
	CImage m_img;
	//�������Ă��鋛�̉摜�f�[�^
	CImage m_img2;
	//���̉摜�f�[�^
	CImage m_img_fish1;
	CImage m_img_fish2;
	CImage m_img_fish3;
	//�X�R�A�\���p�̕����\���I�u�W�F�N�g
	CFont m_UI_text;
	//�摜��`�p�̕ϐ�
	int hp;
	//UI�̔��ʗp�̕ϐ�
	int UI_number;
	//�v���C���[�̃|�C���^�[
	Task* p_player;
public:
	//�R���X�g���N�^
	UI(const CVector3D& pos,int UI_Nunber);
	//�f�X�g���N�^
	~UI();
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;
};