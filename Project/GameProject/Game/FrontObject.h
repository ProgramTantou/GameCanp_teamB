#pragma once
#include "Task.h"

class FrontObject : public Task
{
	FrontObject();
	void Update() override;
	void Render() override;

};