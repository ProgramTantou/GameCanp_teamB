#pragma once
#include<GLLibrary.h>

enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimAttack00,
	eAnimAttack01,
	eAnimAttack02,
	eAnimAttack03,
	eAnimDamage,
	eAnimDown,
};

//�v���C���[�̃A�j���[�V�����f�[�^
extern TexAnimData player_anim_data[];
//�G�̃A�j���[�V�����f�[�^
extern TexAnimData enemy_anim_data[];
//���̃A�j���[�V�����f�[�^
extern TexAnimData fish_anim_data[];
