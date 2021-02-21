#pragma once

#include "Game.h"

struct CoordinatesComponent
{
	CoordinatesComponent();
	CoordinatesComponent(int xPosition, int yPosition);

	void Restart();

	int xPosition, yPosition;
	int startXPosition, startYPostition;
};