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

//プレイヤーのアニメーションデータ
extern TexAnimData player_animdata[];
//敵のアニメーションデータ
extern TexAnimData enemy_anim_data[];

