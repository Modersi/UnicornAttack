#pragma once

#include "Game.h"

struct TimerComponent
{
	TimerComponent();

	int GetTimeInMilliseconds();
	int GetTimeInSeconds();
	int GetTimeInMinutes();
	int GetTimeInHours();
	
	std::string GetTimeInString();
	
	void Restart();
private:
	int lastCheckpointTime;
};
