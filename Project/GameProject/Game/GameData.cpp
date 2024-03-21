#include "GameData.h"

int GameData::m_score = 0;
int GameData::m_max_score = 0;
int GameData::m_time = 300; //5��
bool GameData::clear_flag = false;
bool GameData::death_flag = false;
int GameData::Stage_number = 1;
int GameData::GetFish1 = 0;
int GameData::GetFish2 = 0;
int GameData::GetFish3 = 0;
int GameData::Enemy_rest = 0;


//�R���X�g���N�^
GameData::GameData() : Task(eType_UI,(int)TaskPrio::UI),
m_fontsize(32),
m_GameData_text("C:\\Windows\\Fonts\\msgothic.ttc", m_fontsize){
	//�^�C������p�̕ϐ�
	m_count = 0;
	//�X�R�A�̏�����
	GameData::m_score = 0;
	//�^�C���̏�����
	GameData::m_time = 300;
	Score_flag = false;
}

//�f�X�g���N�^
GameData::~GameData() {
	
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
	//�Q�[���N���A����1�x�����^�C���X�R�A�����Z
	if (GameData::clear_flag == true) {
		if (Score_flag == false) {
			GameData::m_score += m_time * 10;
			//�X�R�A���ō��X�R�A��荂����΍X�V
			if (GameData::m_score > GameData::m_max_score) {
				GameData::m_max_score = GameData::m_score;
			}
			Score_flag = true;
		}
	}
	//�Q�[���I�[�o�[���ɃX�R�A��r
	if (GameData::death_flag == true) {
		//�X�R�A���ō��X�R�A��荂����΍X�V
		if (GameData::m_score > GameData::m_max_score) {
			GameData::m_max_score = GameData::m_score;
		}
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
		if (GameData::Stage_number <= 3) {
			m_GameData_text.Draw(1328, 70, 1, 1, 1, "�c��̓G�̐�");
			m_GameData_text.Draw(1400, 100, 1, 1, 1, "%d��", GameData::Enemy_rest);
		}
		if (GameData::Stage_number >= 4) {
			m_GameData_text.Draw(1328, 70, 1, 1, 1, "�{�X��|���I");
		}
	}
	//�Q�[���N���A���Q�[���I�[�o�[�ɂȂ����Ȃ�
	else if(GameData::clear_flag == true || GameData::death_flag == true) {
		//�ŏI�X�R�A��\��
		//m_GameData_text.Draw(880, 540, 0, 0, 0, "SCORE:%d",GameData::m_score);
	}
}