#pragma once
#include "Task.h"

class Fade : public Task {
private:
	//�摜�f�[�^
	CImage m_img;
	//�o�ߎ��Ԃ̕ϐ�
	int time;
	//�A���t�@�l�̕ϐ�
	float Arufa;
	//�A���t�@�l����p�̃t���O
	bool Arufa_flag;
public:
	//�R���X�g���N�^
	Fade();
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;
};
