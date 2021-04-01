#include "TimerComponent.h"

TimerComponent::TimerComponent() : 
	lastCheckpointTime(SDL_GetTicks()) 
{}

int TimerComponent::GetTimeInMilliseconds()
{
	return SDL_GetTicks() - lastCheckpointTime;
}

int TimerComponent::GetTimeInSeconds()
{
	return (SDL_GetTicks() - lastCheckpointTime) / 1000;
}

int TimerComponent::GetTimeInMinutes()
{
	return (SDL_GetTicks() - lastCheckpointTime) / 60000;
}

int TimerComponent::GetTimeInHours() 
{
	return ((SDL_GetTicks() - lastCheckpointTime) / 60000) / 60;
}

std::string TimerComponent::GetTimeInString()
{
	std::stringstream timeInString;
	timeInString << std::setfill('0') << std::setw(2) << this->GetTimeInHours() << ":"
				 << std::setfill('0') << std::setw(2) << this->GetTimeInMinutes() % 60 << ":"
				 << std::setfill('0') << std::setw(2) << this->GetTimeInSeconds() % 60;
	return timeInString.str();
}


void TimerComponent::Restart()
{
	lastCheckpointTime = SDL_GetTicks();
}
