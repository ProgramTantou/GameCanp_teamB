#pragma once
#include<GLLibrary.h>

enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimAttack01,
	eAnimAttack01End,
	eAnimAttack02,
	eAnimAttack02End,
	eAnimAttack03,
	eAnimAttack03End,
	eAnimDamage,
	eAnimDamageEnd,
	eAnimDown,
};

//�v���C���[�̃A�j���[�V�����f�[�^
extern TexAnimData player_animdata[];
//�G�̃A�j���[�V�����f�[�^
extern TexAnimData enemy_anim_data[];

