#pragma once
#include"Task.h"
#include "TaskManager.h"

class Game :public Task {
public:
	Game();
	~Game();
	void Update() override;
	bool Fade_flag;
	bool Plus_flag;
};