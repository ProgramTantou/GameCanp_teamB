#include "Player.h"

//�R���X�g���N�^
Player::Player() {
	m_pos = CVector2D(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.75f);

	//�v���C���[�̃A�j���[�V�����f�[�^�𐶐�
	int flame = 6;
	mp_animData = new TexAnimData[2]
	{
		//�ҋ@�A�j���[�V����
		{
			new TexAnim[6]{
				{0,flame},{1,flame},{2,flame},
				{3,flame},{4,flame},{5,flame},
			},
			6
		},
		//�ړ��A�j���[�V����
		{
			new TexAnim[6]{
				{6,flame},{7,flame},{8,flame},
				{9,flame},{10,flame},{11,flame},
			},
			6
		},
	};

	//�v���C���[�̉摜��ǂݍ���
	mp_image = CImage::CreateImage("player.png");
}

//�f�X�g���N�^
Player::~Player() {

}

//�v���C���[�̍��W���擾
CVector2D Player::GetPos()
{
	return m_pos;
}

//�v���C���[�̍��W��ݒ�
void Player::SetPos(CVector2D pos) {
	m_pos = pos;
}