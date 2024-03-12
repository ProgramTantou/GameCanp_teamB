#pragma once
#include"Task.h"

class Game :public Task {
public:
	Game();
	~Game();
	void Update() override;
};