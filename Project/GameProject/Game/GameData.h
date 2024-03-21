#pragma once
#include "Task.h"

class GameData : public Task {
public:
	static int m_score; //�ŏI�X�R�A
	static int m_time;  //�c�莞��
	static int m_max_score; //�ō��X�R�A
	static bool clear_flag; //�Q�[���N���A�m�F�p�̃t���O
	static bool death_flag; //�Q�[���I�[�o�[�m�F�p�̃t���O
	static int Stage_number; //�X�e�[�W�ύX�p�ϐ�
	static int GetFish1; //1��ޖڂ̋��̓��萔
	static int GetFish2; //2��ޖڂ̋��̓��萔
	static int GetFish3; //3��ޖڂ̋��̓��萔
	static int Enemy_rest; //�G�̎c��̐�
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
	bool Score_flag; //�X�R�A���Z����p�t���O
};
