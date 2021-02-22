#pragma once

#include "Game.h"
#include "../Components/FontComponent.h"
#include "../Components/CoordinatesComponent.h"
#include  "../Components/TimerComponent.h"

constexpr auto GAME_TIMER_X_POSITION = (SCREEN_WIDTH / 2) - 110;
constexpr auto GAME_TIMER_Y_POSITION = 0;

constexpr auto GAME_TIMER_FONT_FILE_PATH = DEFAULT_FONT_FILE_PATH;
constexpr auto GAME_TIMER_FONT_SIZE		 = DEFAULT_FONT_SIZE;
constexpr auto GAME_TIMER_FONT_COLOR	 = SDL_Color({ 0, 0, 0, 0 });

struct GameTimer
{
	GameTimer();
		
	void Render();

	void Restart();

	CoordinatesComponent gameTimerCoordinates;
	FontComponent gameTimerFont;
	TimerComponent timer;
};