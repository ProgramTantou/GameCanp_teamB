#pragma once
#include<GLLibrary.h>

enum {
	eAnimIdle=0,
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimAttack01,
	eAnimAttack02,
	eAnimAttack03,
	eAnimDamage,
	eAnimDown,
};

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
//敵のアニメーションデータ
extern TexAnimData enemy_anim_data[];

