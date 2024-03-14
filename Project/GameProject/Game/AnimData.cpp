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
