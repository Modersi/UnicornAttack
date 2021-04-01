#pragma once

#include "../Game/Game.h"

struct CoordinatesComponent
{
	CoordinatesComponent();
	CoordinatesComponent(int xPosition, int yPosition);

	void operator = (const SDL_Rect& sdlRectangle);
	void operator = (const b2Vec2& box2dVector);

	void Restart();

	int xPosition, yPosition;
	int startXPosition, startYPosition;
};