#include "Field.h"

//�R���X�g���N�^
Field::Field() :Base(eType_Field)
	,m_pos(960.0f,540.0f)
	//,mp_image(nullptr)
{
	mp_image = COPY_RESOURCE("Field", CImage);
	
	m_ground_y = 300;
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
void Field::Draw() {
	float sc;
	mp_image.Draw();
	//sc = m_scroll.x
}