#pragma once
#include "Task.h"

class GameData : public Task {
public:
	static int m_score; //�ŏI�X�R�A
	static int m_time;  //�c�莞��
	static int m_max_score; //�ō��X�R�A
	static bool clear_flag; //�Q�[���N���A�m�F�p�̃t���O
	static bool death_flag; //�Q�[���I�[�o�[�m�F�p�̃t���O
	//�R���X�g���N�^
	GameData();
	//�f�X�g���N�^
	~GameData();
private:
	int m_count;        //���Ԍv�Z�p�̕ϐ�
	int m_fontsize;     //�����傫���̃T�C�Y
	CFont m_GameData_text;  //�����\���I�u�W�F�N�g
	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;
};
