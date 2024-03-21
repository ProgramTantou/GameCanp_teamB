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
	ANIMDATA(playerAttack00),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDown),
};

static TexAnim fish_1Move[] =
{
	{0,frame},
	{1,frame},
	{2,frame},
};


static TexAnim fish_1Attack[] = 
{
	{16,frame},
	{17,frame},
	{18,frame},
	
};

static TexAnim fish_1Down[] =
{
	{32,frame},
	{33,frame},
	{34,frame},
};

TexAnimData fish_anim_data_1[] = {
	ANIMDATA(fish_1Move),
	ANIMDATA(fish_1Attack),
	ANIMDATA(fish_1Down),
};
static TexAnim fish_2Move[] =
{
	{0,frame},
	{1,frame},
	{2,frame},
};


static TexAnim fish_2Attack[] =
{
	{24,frame},
	{25,frame},
	{26,frame},
	
};

static TexAnim fish_2Down[] =
{
	{8,frame},
	{9,frame},
	{10,frame},
};

TexAnimData fish_anim_data_2[] = {
	ANIMDATA(fish_2Move),
	ANIMDATA(fish_2Attack),
	ANIMDATA(fish_2Down),
};

static TexAnim fish_3Move[] =
{
	{}
};


static TexAnim fish_3Attack[] =
{
	{}
};

static TexAnim fish_3Down[] =
{
	{}
};

TexAnimData fish_anim_data_3[] = {
	ANIMDATA(fish_3Move),
	ANIMDATA(fish_3Attack),
	ANIMDATA(fish_3Down),
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


static TexAnim bossRun[] = {
	{0,frame},
	{1,frame},
};

static TexAnim bossAttack[] = {
	{8,frame},
	{9,frame},
	{10,frame},
	{11,frame},
	{12,frame},
};

static TexAnim bossDamage[] = {
	{24,frame},
	{25,frame},
	{26,frame},
};

static TexAnim bossDead[] = {
	{16,frame},
	{17,frame},
	{18,frame},
	{19,frame},
	{20,frame},
	{21,frame},
	{22,frame},
};

TexAnimData boss_anim_data[] = {
	ANIMDATA(bossRun),
	ANIMDATA(bossAttack),
	ANIMDATA(bossDamage),
	ANIMDATA(bossDead),

};