#include "CoordinatesComponent.h"

CoordinatesComponent::CoordinatesComponent() :
	xPosition{ 0 },
	yPosition{ 0 },
	startXPosition{ 0 },
	startYPostition{ 0 } 
{}

CoordinatesComponent::CoordinatesComponent(int xPosition, int yPosition) :
	xPosition{ xPosition },
	yPosition{ yPosition },
	startXPosition{ xPosition },
	startYPostition{ yPosition } 
{}

void CoordinatesComponent::Restart()
{
	xPosition = startXPosition;
	yPosition = startYPostition;
}
