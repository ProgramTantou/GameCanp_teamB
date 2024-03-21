#include "MostFront.h"

//�R���X�g���N�^
MostFront::MostFront(int Field_Number) : ObjectBase(eType_MostFront) {
	//�����̑��
	Field_number = Field_Number;
	//�J�E���g�̏�����
	count = 0;
	count2 = 0;
	//�����ɂ��ǂݍ��݉摜�̕���
	switch (Field_number) {
	case 1:
		mp_image_Light = COPY_RESOURCE("Light_1", CImage);
		mp_image_Underwater = COPY_RESOURCE("Underwater_1", CImage);
		break;
	case 2:
		mp_image_Light = COPY_RESOURCE("Light_2", CImage);
		mp_image_Underwater = COPY_RESOURCE("Underwater_2", CImage);
		break;
	default:
		break;
	}
}

//�X�V����
void MostFront::Update() {
	//�Ăяo�����ɂ��ꂼ��̃J�E���g��+1
	count++;
	count2++;
}

//�`�揈��
void MostFront::Render() {
	//�X�N���[���l
	float sc;
	//�g�̗h��̕\��
	sc = ObjectBase::m_scroll.x + sin(DtoR(count)) * 16;
	mp_image_Underwater.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Underwater.Draw();
	//���̋���̕\��
	sc = ObjectBase::m_scroll.x;
	mp_image_Light.SetRect(sc, 0, sc + 1920, 1080);
	mp_image_Light.SetColor(1, 1, 1, 0.2 + sin(DtoR(count2)) * 0.1);
	mp_image_Light.Draw();
}