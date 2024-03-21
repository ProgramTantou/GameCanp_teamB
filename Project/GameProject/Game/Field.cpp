#include "Field.h"
#include "Enemy.h"
#include "Boss.h"
#include "GameData.h"

bool Field::Next_flag = false;

//�R���X�g���N�^
Field::Field(int stage_number) : Task(eType_Field, (int)TaskPrio::Field)
{
	Stage_number = stage_number;
	//�G�̈ʒu����p�ϐ��̏�����
	Enemy_pos_Control = 0;
	//���̃X�e�[�W�ɍs���邩�̔���p�t���O�̏�����
	Field::Next_flag = false;
	//�t�B�[���h�i���o�[�ɂ��ǂݍ��݉摜�̕���
	switch (Stage_number)
	{
	case 1:
	case 2:
	case 3:
		//���邢�w�i
		mp_image_Back = COPY_RESOURCE("Back_1", CImage);
		mp_image_Field = COPY_RESOURCE("Field_1", CImage);
		mp_image_Pillar = COPY_RESOURCE("Pillar_1", CImage);
		break;
	case 4:
		//�Â��w�i
		mp_image_Back = COPY_RESOURCE("Back_2", CImage);
		mp_image_Field = COPY_RESOURCE("Field_2", CImage);
		mp_image_Pillar = COPY_RESOURCE("Pillar_2", CImage);
		break;
	}
	//�X�e�[�W�i���o�[�ɂ��G�����̕���
	switch (Stage_number) {
	case 1:
		//�G1��7��,�G2��1�́A�G3��1��
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				Enemy_pos_Control += 1;
			}
			new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, i * -50), 0, false);
		}
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 7 * -50), 1, false);
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 8 * -50), 2, false);
		break;
	case 2:
		//�G2��7��,�G3��1�́A�G1��1��
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				Enemy_pos_Control += 1;
			}
			new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, i * -50), 1, false);
		}
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 7 * -50), 2, false);
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 8 * -50), 0, false);
		break;
	case 3:
		//�G3��7��,�G1��1�́A�G2��1��
		for (int i = 0; i < 7; i++) {
			if (i % 3 == 0) {
				Enemy_pos_Control += 1;
			}
			new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, i * -50), 2, false);
		}
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 7 * -50), 0, false);
		new Enemy(CVector3D(200 + 900 * Enemy_pos_Control, 650, 8 * -50), 1, false);
		break;
	case 4:
		//�{�X��1��
		new Boss(CVector3D(2900, 650, -100),  false);
		break;
	default:
		break;
	}
	//�n�ʂ̍���
	m_ground_y = 800;
}

//�f�X�g���N�^
Field::~Field() {
	
}

//�t�B�[���h�̍��W��ݒ�
void Field::SetPos(const CVector2D& pos) {
	m_pos = pos;
}

//�t�B�[���h�̍������擾
const float Field::GetGroundY(){
	return m_ground_y;
}

//�X�V����
void Field::Update() {
	if (!TaskManager::FindObject(eType_Enemy)) {
		Field::Next_flag = true;
	}
	//if (PUSH(CInput::eButton5)) {
		//Field::Next_flag = true;
	//}
}

//�`�揈��
void Field::Render() {
	float sc;
	sc = ObjectBase::m_scroll.x / 4;
	mp_image_Back.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Back.Draw();

	sc = ObjectBase::m_scroll.x / 2;
	mp_image_Pillar.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Pillar.Draw();

	sc = ObjectBase::m_scroll.x;
	mp_image_Field.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Field.Draw();
}