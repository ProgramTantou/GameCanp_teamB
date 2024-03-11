#include"Game.h"
#include"Player.h"
#include"Enemy.h"
#include"Field.h"
#include"UI.h"
#include"GameData.h"


Game::Game() :Base(eType_Scene) 
{
	Base::Add(new Field());
	Base::Add(new Player(CVector3D(700, 1000, 0), false));
	Base::Add(new Enemy(CVector3D(1000, 500, 0),1,false));
	Base::Add(new UI(CVector2D(100, 150), 1));
	Base::Add(new GameData());
}

Game::~Game()
{
	Base::KillAll();
	//Base::Add(new Title());
}

void Game::Update()
{

	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton5)) {
		SetKill();
	}
}
