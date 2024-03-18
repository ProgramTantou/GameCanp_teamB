#include "GameData.h"

int GameData::m_score = 0;
int GameData::m_time = 180; //3��
bool GameData::clear_flag = false;
bool GameData::death_flag = false;

//�R���X�g���N�^
GameData::GameData() : Task(eType_UI,(int)TaskPrio::UI),
m_fontsize(32),
m_GameData_text("C:\\Windows\\Fonts\\msgothic.ttc", m_fontsize){
	m_count = 0;
	GameData::m_score = 0;
	GameData::m_time = 180;
}

//�f�X�g���N�^
GameData::~GameData() {
	//�Q�[�����N���A�����Ȃ�
	if (GameData::clear_flag == true) {
		//�X�R�A�Ɏc��^�C�������Z
		GameData::m_score += m_time * 10;
	}
}

//�X�V����
void GameData::Update() {
	//1�t���[������+1
	m_count++;
	//�Q�[���N���A�ł��Q�[���I�[�o�[�łȂ��Ȃ�
	if (GameData::clear_flag == false && GameData::death_flag == false) {
		//�J�E���g��60�Ŋ���؂��Ȃ�
		if (m_count % 60 == 0) {
			//�c�莞��-1
			m_time -= 1;
			m_count = 0;
		}
	}
	//�Q�[���N���A���Q�[���I�[�o�[�ɂȂ����Ȃ�
	if (GameData::clear_flag == true || GameData::death_flag == true) {
		//�t�H���g�T�C�Y4�{
		m_fontsize *= 4;
	}
}

//�`�揈��
void GameData::Render() {
	//�Q�[���N���A�ł��Q�[���I�[�o�[�łȂ��Ȃ�
	if (GameData::clear_flag == false && GameData::death_flag == false) {
		//�E��Ɍ��݃X�R�A�Ǝc��^�C����\��
		m_GameData_text.Draw(1800, 70, 1, 1, 1, "TIME");
		m_GameData_text.Draw(1800, 100, 1, 1, 1, "%d",GameData::m_time);
		m_GameData_text.Draw(1600, 70, 1, 1, 1, "SCORE");
		m_GameData_text.Draw(1600, 100, 1, 1, 1, "%d",GameData::m_score);
	}
	//�Q�[���N���A���Q�[���I�[�o�[�ɂȂ����Ȃ�
	else if(GameData::clear_flag == true || GameData::death_flag == true) {
		//�ŏI�X�R�A��\��
		m_GameData_text.Draw(880, 540, 0, 0, 0, "SCORE:%d",GameData::m_score);
	}
}