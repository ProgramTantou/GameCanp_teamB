#include"AnimData.h"


int frame = 10;

static TexAnim playerIdle[] = {
	{0,frame},
	{8,frame},
	{16,frame},
	{24,frame},
	{32,frame},
};
static TexAnim playerRun[] = {
	{1,frame},
	{9,frame},
	{17,frame},
	{25,frame},
};
static TexAnim playerJumpUp[] = {
	{2,frame},
	{10,frame},
};
static TexAnim playerJumpDown[] = {
	{10,frame},
	{2,frame},
};
static TexAnim playerAttack01[]{
	{4,frame},
};

static TexAnim playerAttack02[]{
	{12,frame},
};
static TexAnim playerAttack03[]{
	{20,frame},
};


static TexAnim playerDamage[] = {
	{6,frame},
	{14,frame},
	{22,frame},
};



static TexAnim playerDown[] = {
	{5,frame},
	{13,frame},
	{21,frame},
	{29,frame},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDown),
};


static TexAnim enemyRun[] = {
	{0,frame},
	{1,frame},
};

static TexAnim enemyAttack01[] = {
	{8,frame},
	{9,frame},
	{10,frame},
};

static TexAnim enemyAttack02[] = {
	{}
};

static TexAnim enemyAttack03[] = {
	{}
};

static TexAnim enemyDamage[] = {
	{}
};
static TexAnim enemyDown[] = {
	{24,frame-5},
	{25,frame-5},
	{26,frame},
	{27,frame},
};
TexAnimData enemy_anim_data[] = {
	
	ANIMDATA(enemyRun),
	ANIMDATA(enemyAttack01),
	ANIMDATA(enemyAttack02),
	ANIMDATA(enemyAttack03),
	ANIMDATA(enemyDamage),
	ANIMDATA(enemyDown),
	
};
