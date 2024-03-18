#include"Game.h"
#include"Player.h"
#include"Enemy.h"
#include"Field.h"
#include"UI.h"
#include"GameData.h"
#include"GameOver.h"
#include "TaskManager.h"
#include "Fade.h"
#include"FishManager.h"


Game::Game() :Task(eType_Scene,(int)TaskPrio::Scene) 
{
	GameData::clear_flag == false;
	GameData::death_flag == false;
	new Field(1);
	new Player(CVector3D(200, 1000, 0), false);
	new FishManager();
	//new Enemy(CVector3D(1000, 500, 0),1,false);
	//new Enemy(CVector3D(1500, 500, 0), 0, false);
	new Enemy(CVector3D(1200, 500, 0), 2, false);
	new UI(CVector2D(10, 120), 1);
	new GameData();
	//new Fade();
}

Game::~Game()
{
	TaskManager::KillAll();
	new GameOver(CVector2D(900, 600));
	//TaskManager::DeleteAll();
	//Base::Add(new Title());
}

void Game::Update()
{

	if (!TaskManager::FindObject(eType_Player) && PUSH(CInput::eButton5)) {
		Kill();
	}
}
