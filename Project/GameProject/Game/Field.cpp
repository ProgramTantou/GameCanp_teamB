#include "Field.h"
#include "Enemy.h"
#include "Boss.h"

int Field::Stage_number = 1;

//�R���X�g���N�^
Field::Field(int Field_Nunber) : Task(eType_Field, (int)TaskPrio::Field)
	//,mp_image(nullptr)
{
	//�t�B�[���h�i���o�[�̑��
	Field_number = Field_Nunber;
	//�t�B�[���h�i���o�[�ɂ��ǂݍ��݉摜�̕���
	switch (Field_number)
	{
	case 1:
		//���邢�w�i
		mp_image = COPY_RESOURCE("Field_1", CImage);
		break;
	case 2:
		//�Â��w�i
		mp_image = COPY_RESOURCE("Field_2", CImage);
		break;
	}
	//�X�e�[�W�i���o�[�ɂ��G�����̕���
	switch (Field::Stage_number) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	default:
		break;
	}
	//�n�ʂ̍���
	m_ground_y = 800;
}

//�f�X�g���N�^
Field::~Field() {
	//�폜�����x�ɃX�e�[�W�i���o�[+1
	Field::Stage_number += 1;
	//�X�e�[�W�i���o�[��4��菬�����Ȃ�
	if (Field::Stage_number < 4) {
		//���邢�w�i�̃X�e�[�W�𐶐�
		new Field(1);
	}
	//�X�e�[�W�i���o�[��4�Ȃ�
	else if(Field::Stage_number == 4) {
		//�Â��w�i�̃X�e�[�W�𐶐�
		new Field(2);
	}
	//����ȊO�̃i���o�[�Ȃ�
	else {
		//�������Ȃ�
	}
}

//�t�B�[���h�̍��W���擾
/*const CVector2D& Field::GetPos() const {
	
}*/

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
	
}

//�`�揈��
void Field::Render() {
	float sc;
	sc = ObjectBase::m_scroll.x;
	mp_image.SetRect(sc, 0, sc + 1920, 1080);
	mp_image.Draw();
}