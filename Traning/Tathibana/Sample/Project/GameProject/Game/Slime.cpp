#include"Slime.h"

//�R���X�g���N�^
Slime::Slime(int type,const CVector2D&pos)
	:m_pos(pos)
	,mp_animData(nullptr)
	,mp_image(nullptr)
	, m_hp(100)
	,m_type(type)
{
	

	//�v���C���[�̃A�j���[�V�����f�[�^�𐶐�
	int frame = 6;
	mp_animData = new TexAnimData[1]
	{
		{
			new TexAnim[4]
			{
				{ 0, frame}, { 1, frame}, 
				{ 2, frame}, { 3, frame},
			},
			4
		},
	};

	//�v���C���[�摜�̓ǂݍ���
	std::string imagePath;


	if (m_type == 0)imagePath = "slime_a.png";
	else if (m_type == 1)imagePath = "slime_b.png";
	else if (m_type == 2)imagePath = "slime_c.png";
	//�摜�t�@�C���p�X�E�A�j���[�V�����̃f�[�^�E1�R�}�̕�(float.x)�ƍ���(float.y)
	mp_image = CImage::CreateImage(imagePath.c_str(), mp_animData, 256.0f, 256.0f);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(128.0f, 184.0f);
	mp_image->SetFlipH(true);

}

//�f�X�g���N�^
Slime::~Slime()
{
	//�A�j���[�V�����f�[�^�̔z����폜
	for (int i = 0; i < 2; i++) {
		delete[]mp_animData[i].pData;
	}
	delete[]mp_animData;
	//�摜�f�[�^���폜
	delete mp_image;
}


//�v���C���[�̍��W���擾
const CVector2D& Slime::GetPos()const
{
	return m_pos;
}


//�v���C���[�̍��W��ݒ�
void Slime::SetPos(const CVector2D& pos)
{
	m_pos = pos;
}

//�X�V����
void Slime::Update()
{
	//�C���[�W�ɍ��W��ݒ肵�āA�A�j���[�V�������X�V
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

//�`�揈��
void Slime::Render()
{
	mp_image->Draw();
}