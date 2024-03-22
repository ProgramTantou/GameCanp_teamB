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
#include "Casol.h"

Game::Game() :Task(eType_Scene,(int)TaskPrio::Scene) 
{
	
	Fade_flag = false;
	Plus_flag = false;
	GameData::Stage_number = 1;
	GameData::clear_flag = false;
	GameData::death_flag = false;
	new Player(CVector3D(200, 1000, 0), false);
	new Field(GameData::Stage_number);
	new FishManager();
	new UI(CVector2D(10, 120), 1);
	new UI(CVector2D(10, 120), 2);
	new GameData();
	new Shadow();
	new Casol();
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
		if (GameData::clear_flag == false && GameData::death_flag == false) {
			if (GameData::Stage_number <= 4) {
				if (Plus_flag == false) {
					GameData::Stage_number += 1;
					Plus_flag = true;
				}
				if (Fade_flag == false) {
					new Fade();
					Fade_flag = true;
				}
				if (Fade::Arufa >= 1) {
					TaskManager::SelectKill(eType_Field);
					TaskManager::SelectKill(eType_MostFront);
					new Field(GameData::Stage_number);
					
					Plus_flag = false;
					Fade_flag = false;
				}
			}
		}
	}
}
