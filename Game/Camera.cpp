#include "Camera.h"

Camera::Camera() : 
	cameraCoordinates(0, 0)
{}

Camera::Camera(int xPosition, int yPosition) :
	cameraCoordinates(xPosition, yPosition)
{}

int Camera::GetXPosition() const
{
	return cameraCoordinates.xPosition;
}

int Camera::GetYPosition() const
{
	return cameraCoordinates.yPosition;
}

void Camera::SetPosition(const int& xPosition, const int& yPosition)
{
	cameraCoordinates.xPosition = xPosition;
	cameraCoordinates.yPosition = yPosition;
}

void Camera::SetPosition(const SDL_Rect& positionRectangle)
{
	cameraCoordinates.xPosition = positionRectangle.x;
	cameraCoordinates.yPosition = positionRectangle.y;
}

void Camera::SetPosition(const b2Vec2& positionCoordinates)
{
	cameraCoordinates.xPosition = METERS_TO_PIXELS(positionCoordinates.x);
	cameraCoordinates.yPosition = METERS_TO_PIXELS(positionCoordinates.y);
}

void Camera::SetPosition(const CoordinatesComponent& positionCoordinates)
{
	cameraCoordinates = positionCoordinates;
}

void Camera::Restart()
{
	cameraCoordinates.Restart();
}
