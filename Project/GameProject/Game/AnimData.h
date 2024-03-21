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

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
//敵のアニメーションデータ
extern TexAnimData enemy_anim_data[];
//魚のアニメーションデータ
extern TexAnimData fish_anim_data[];
