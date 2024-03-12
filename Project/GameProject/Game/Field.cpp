#include "Field.h"


//�R���X�g���N�^
Field::Field() : Task(eType_Field, (int)TaskPrio::Field)
	//,mp_image(nullptr)
{
	mp_image = COPY_RESOURCE("Field", CImage);
	
	m_ground_y = 800;
}

//�f�X�g���N�^
Field::~Field() {
	
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
	sc = m_scroll.x;
	mp_image.SetRect(sc, 0, sc + 1920, 1080);
	mp_image.Draw();
}