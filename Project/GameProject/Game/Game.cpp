#include"Game.h"
#include"Player.h"
#include"Enemy.h"
#include"Field.h"
#include"UI.h"
#include"GameData.h"
#include "TaskManager.h"


Game::Game() :Task(eType_Scene,(int)TaskPrio::Scene) 
{
	new Field(2);
	new Player(CVector3D(700, 1000, 0), false);
	new Enemy(CVector3D(1000, 500, 0),1,false);
	new UI(CVector2D(10, 120), 1);
	new GameData();
}

Game::~Game()
{
	//TaskManager::DeleteAll();
	//Base::Add(new Title());
}

void Game::Update()
{

	if (!TaskManager::FindObject(eType_Player) && PUSH(CInput::eButton5)) {
		Kill();
	}
}
