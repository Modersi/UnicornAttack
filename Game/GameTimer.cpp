#include "GameTimer.h"

GameTimer::GameTimer()
{
	gameTimerCoordinates = CoordinatesComponent(GAME_TIMER_X_POSITION, GAME_TIMER_Y_POSITION);
	gameTimerFont = FontComponent(GAME_TIMER_FONT_SIZE, GAME_TIMER_FONT_FILE_PATH);
	timer = TimerComponent();
}

void GameTimer::Render()
{
	gameTimerFont.DrawText(timer.GetTimeInString(), gameTimerCoordinates, GAME_TIMER_FONT_COLOR);
}

void GameTimer::Restart()
{
	timer.Restart();
}





