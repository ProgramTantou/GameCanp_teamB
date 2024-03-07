#include "Player.h"

//�R���X�g���N�^
Player::Player() 
	:CharaBase(CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f)) //�R���X�g���N�^�ɒl��n���Ă���
	, mp_animData(nullptr)
	, mp_image(nullptr)
	//�������q���X�g
{
	m_hp = 200;

	//�v���C���[�̃A�j���[�V�����f�[�^�𐶐�
	int frame = 6;
	mp_animData = new TexAnimData[2]
	{
		//�ҋ@�A�j���[�V����
		{
			new TexAnim[6]{
				{0,frame},{1,frame},{2,frame},
				{3,frame},{4,frame},{5,frame},
			},
			6
		},
		//�ړ��A�j���[�V����
		{
			new TexAnim[6]{
				{6,frame},{7,frame},{8,frame},
				{9,frame},{10,frame},{11,frame},
			},
			6
		},
	};

	//�v���C���[�̉摜��ǂݍ���
	mp_image = CImage::CreateImage
	("player.png",   //�摜�t�@�C���̃p�X
	mp_animData,     //�A�j���[�V�����̃f�[�^
	384.0f,384.0f    //1�R�}�̕��ƍ���
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(192.0f, 328.0f);
}

//�f�X�g���N�^
Player::~Player() {
	//�A�j���[�V�����f�[�^�̔z����폜
	for (int i = 0; i < 2; i++) {
		delete[] mp_animData[i].pData;
	}
	delete[] mp_animData;

	//�摜�f�[�^���폜
	delete mp_image;
}

//���S�������̏���
void Player::Death() {
	//���N���X�̎��S�������Ăяo��
	CharaBase::Death();

	//���S�A�j���[�V�������Đ����āA
	//���S�A�j���[�V�������I�������A
	//�Q�[���I�[�o�[��ʂ�\������
}

//�X�V����
void Player::Update() {
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
	else if(HOLD(CInput::eDown)) {
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

//�`�揈��
void Player::Render() {
	mp_image->Draw();
}