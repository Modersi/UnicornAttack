#pragma once

#include "Game.h"
#include "../Components/CoordinatesComponent.h"

class Camera
{
public:
	Camera();
	Camera(int xPosition, int yPosition);

	int GetXPosition() const;
	int GetYPosition() const;

	void SetPosition(const int& xPosition, const int& yPosition);
	void SetPosition(const SDL_Rect& positionRectangle);
	void SetPosition(const b2Vec2& positionCoordinates);
	void SetPosition(const CoordinatesComponent& positionCoordinates);

	void Restart();

private:
	CoordinatesComponent cameraCoordinates;
};
