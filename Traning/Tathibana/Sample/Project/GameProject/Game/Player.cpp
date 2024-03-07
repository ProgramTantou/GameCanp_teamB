#include"Player.h"

//�R���X�g���N�^
Player::Player()
	:CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f))
	, mp_animData(nullptr)
	, mp_image(nullptr)
	
	
{
	m_hp = 200;
	//�v���C���[�̃A�j���[�V�����f�[�^�𐶐�
	int frame = 6;
	mp_animData = new TexAnimData[2]
	{
		//�ҋ@�A�j���\�V����
		{
			new TexAnim[6]
			{
				{0,frame},{1,frame},{2,frame},
				{3,frame},{4,frame},{5,frame},
			},6
		},
		//�ړ��A�j���[�V����
		{
			new TexAnim[6]
			{
				{6,frame},{7,frame},{8,frame},
				{9,frame},{10,frame},{11,frame},

			},6
		},
	};

	//�v���C���[�摜�̓ǂݍ���

	//�摜�t�@�C���p�X�E�A�j���[�V�����̃f�[�^�E1�R�}�̕�(float.x)�ƍ���(float.y)
	mp_image = CImage::CreateImage("Player.png",mp_animData,384.0f,384.0f);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);

	
}

//�f�X�g���N�^
Player::~Player() 
{
	//�A�j���[�V�����f�[�^�̔z����폜
	for (int i = 0; i < 2; i++) {
		delete[]mp_animData[i].pData;
	}
	delete[]mp_animData;
	//�摜�f�[�^���폜
	delete mp_image;
}


//�X�V����
void Player::Update()
{
	bool isMove = false;
	//���L�[�������Ă����
	if (HOLD(CInput::eLeft))
	{
		//�������ֈړ�
		m_pos.x -= 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(true);
		isMove = true;
	}
	//�E�L�[�������Ă����
	else if (HOLD(CInput::eRight))
	{

		//�E�����ֈړ�
		m_pos.x += 8.0f;
		mp_image->ChangeAnimation(1);
		mp_image->SetFlipH(false);
		isMove = true;
	}
	if (HOLD(CInput::eUp)) {
		m_pos.y -= 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	else if (HOLD(CInput::eDown)) {
		m_pos.y += 3.0f;
		mp_image->ChangeAnimation(1);
		isMove = true;
	}
	//���E�L�[�ǂ����������Ă��Ȃ��ꍇ
	if(!isMove)
	{
		//�ҋ@�A�j���[�V�������Đ�
		mp_image->ChangeAnimation(0);
	}
	//�C���[�W�ɍ��W��ݒ肵�āA�A�j���[�V�������X�V
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

void Player::Death() {
	//���N���X�̎��S�������Ăяo��
	CharaBase::Death();

	//���S�A�j���[�V�������Đ�
	//�Đ����I��莟��Q�[���I�[�o�[��ʂ�\��
}

//�`�揈��
void Player::Render()
{
	mp_image->Draw();
}