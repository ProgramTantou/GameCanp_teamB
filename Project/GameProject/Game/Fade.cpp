#include "Fade.h"

//�R���X�g���N�^
Fade::Fade() : Task(eType_Scene, (int)TaskPrio::Fade) {
	//�^�C���̏�����
	time = 0;
	//�A���t�@�l�̏�����
	Arufa = 0.00;
	//�A���t�@�l����p�̃t���O
	Arufa_flag = false;
}

//�X�V����
void Fade::Update() {
	//�A���t�@�t���O�������Ă��炸�A���t�@�l��1��菬�����Ȃ�
	if(Arufa_flag == false && Arufa < 1.00){
		//1�t���[�����ɃA���t�@�l+0.05
		Arufa += 0.05;
	}
	//�A���t�@�l��1�ȏ�Ȃ�
	if (Arufa >= 1.0) {
		//1�t���[������time+1
		time++;
		//2�b�o������
		if (time == 120){
			//�A���t�@�t���O�𗧂�
			Arufa_flag = true;
			//time��������
			time = 0;
		}
	}
	//�A���t�@�t���O�������Ă�����
	if (Arufa_flag == true) {
		//1�t���[�����ɃA���t�@�l-0.05
		Arufa -= 0.05;
		//�A���t�@�l��0�ɂȂ�����
		if (Arufa <= 0.00) {
			//Fade�N���X���폜
			Kill();
		}
	}
}

//�`�揈��
void Fade::Render() {
	//���̕`��
	Utility::DrawQuad(CVector2D(0, 0), CVector2D(SCREEN_WIDTH, SCREEN_HEIGHT), CVector4D(0, 0, 0, Arufa));
}