#pragma once
#include "../Base/Base.h"

class GameData : public Base {
public:
	static int m_score; //�ŏI�X�R�A
	static int m_time;  //�c�莞��
	static bool clear_flag; //�Q�[���N���A�m�F�p�̃t���O
	static bool death_flag; //�Q�[���I�[�o�[�m�F�p�̃t���O
	//�R���X�g���N�^
	GameData();
private:
	int m_count;        //���Ԍv�Z�p�̕ϐ�
	int m_fontsize;     //�����傫���̃T�C�Y
	CFont m_GameData_text;  //�����\���I�u�W�F�N�g
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};
