#include"AnimData.h"


int frame = 10;

static TexAnim playerIdle[] = {
	{0,frame},
	{1,frame},
	{2,frame},
	{3,frame},
	{4,frame},
};
static TexAnim playerRun[] = {
	{8,frame},
	{9,frame},
	{10,frame},
	{11,frame},
};
static TexAnim playerJumpUp[] = {
	{16,frame},
	{17,frame},
};
static TexAnim playerJumpDown[] = {
	{17,frame},
	{16,frame},
};
static TexAnim playerAttack00[] = {
	{24,frame},
	{25,frame},
	{26,frame},
	{27,frame},
	{28,frame},
};
static TexAnim playerAttack01[]{
	{48,frame},
};

static TexAnim playerAttack02[]{
	{49,frame},
};
static TexAnim playerAttack03[]{
	{50,frame},
};


static TexAnim playerDamage[] = {
	{40,frame},
	{41,frame},
	{42,frame},
};



static TexAnim playerDown[] = {
	{32,frame},
	{33,frame},
	{34,frame},
	{35,frame},
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

/*/*static TexAnim enemyIdle[] = {
	
};
static TexAnim enemyRun[] = {
	
};
static TexAnim enemyJumpUp[] = {
	
};
static TexAnim enemyJumpDown[] = {
	
};

static TexAnim enemyAttack01[] = {
	
};
static TexAnim enemyAttack01End[] = {
	
};
static TexAnim enemyAttack02[] = {
	
};
static TexAnim enemyAttack02End[] = {
	
};
static TexAnim enemyAttack03[] = {
	
};
static TexAnim enemyAttack03End[] = {
	
};
static TexAnim enemyDamage[] = {
	
};
static TexAnim enemyDown[] = {
	
};
TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyIdle),
	ANIMDATA(enemyRun),
	ANIMDATA(enemyJumpUp),
	ANIMDATA(enemyJumpDown),
	ANIMDATA(enemyAttack01),
	ANIMDATA(enemyAttack01End),
	ANIMDATA(enemyAttack02),
	ANIMDATA(enemyAttack02End),
	ANIMDATA(enemyAttack03),
	ANIMDATA(enemyAttack03End),
	ANIMDATA(enemyDamage),
	ANIMDATA(enemyDamageEnd),
	ANIMDATA(enemyDown),
	
};*/
