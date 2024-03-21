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
#include "Boss.h"
#include "Shadow.h"

Game::Game() :Task(eType_Scene,(int)TaskPrio::Scene) 
{
	GameData::Stage_number = 1;
	GameData::clear_flag = false;
	GameData::death_flag = false;
	new Field(GameData::Stage_number);
	new Player(CVector3D(200, 1000, 0), false);
	new FishManager();
	//new Enemy(CVector3D(1000, 500, 0),1,false);
	//new Enemy(CVector3D(1500, 500, 0), 0, false);
	//new Enemy(CVector3D(1200, 500, 0), 2, false);
	//new Boss(CVector3D(1000, 500, 0), false);
	new UI(CVector2D(10, 120), 1);
	new GameData();
	//new Fade();
	new Shadow();
}

Game::~Game()
{
	//TaskManager::KillAll();
	//new GameOver(CVector2D(900, 600));
	//TaskManager::DeleteAll();
	//Base::Add(new Title());
}

void Game::Update()
{
	if (Field::Next_flag == true) {
		if (GameData::Stage_number < 4) {
			GameData::Stage_number++;
			TaskManager::SelectKill(eType_Field);
			new Field(GameData::Stage_number);
		}
	}
}
