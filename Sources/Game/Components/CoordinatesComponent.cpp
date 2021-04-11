#include "Components/CoordinatesComponent.h"

CoordinatesComponent::CoordinatesComponent() :
	xPosition(0),
	yPosition(0),
	startXPosition(0),
	startYPosition(0)
{}

CoordinatesComponent::CoordinatesComponent(int xPosition, int yPosition) :
	xPosition(xPosition),
	yPosition(yPosition),
	startXPosition(xPosition),
	startYPosition(yPosition)
{}

void CoordinatesComponent::operator=(const SDL_Rect& sdlRectangle)
{
	this->xPosition = sdlRectangle.x;
	this->yPosition = sdlRectangle.y;
}

void CoordinatesComponent::operator=(const b2Vec2& box2dVector)
{
	this->xPosition = METERS_TO_PIXELS(box2dVector.x);
	this->yPosition = -METERS_TO_PIXELS(box2dVector.y);
}

void CoordinatesComponent::Restart()
{
	xPosition = startXPosition;
	yPosition = startYPosition;
}
