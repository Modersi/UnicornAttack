#include "GameTimer.h"

GameTimer::GameTimer() : 
	gameTimerCoordinates(GAME_TIMER_X_POSITION, GAME_TIMER_Y_POSITION),
	gameTimerFont(GAME_TIMER_FONT_SIZE, GAME_TIMER_FONT_FILE_PATH),
	timer()
{}

GameTimer::~GameTimer()
{
	gameTimerFont.DestroyFont();
}

void GameTimer::Render()
{
	gameTimerFont.DrawText(timer.GetTimeInString(), gameTimerCoordinates.xPosition, gameTimerCoordinates.yPosition, GAME_TIMER_FONT_COLOR);
}

void GameTimer::Restart()
{
	timer.Restart();
}





