#include "Field.h"

//�R���X�g���N�^
Field::Field()
	:m_pos()
	,mp_image(nullptr)
{
	//�t�B�[���h�̉摜��ǂݍ���
	mp_image = CImage::CreateImage("Field.png");
	mp_image->SetCenter(960.0f,540.0f);
	m_ground_y = 540;
}

//�f�X�g���N�^
Field::~Field() {
	//�摜�f�[�^���폜
	delete mp_image;
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
	//�C���[�W�ɍ��W��ݒ�
	mp_image->SetPos(m_pos);
}

//�`�揈��
void Field::Draw() {
	float sc;
	mp_image->Draw();
	//sc = m_scroll.x
}