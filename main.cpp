#include "Game/Game.h"

/* Constants needed to make fixed FPS */
constexpr auto TARGET_FPS =			60;
constexpr auto TARGET_FRAME_TIME =	(1000 / TARGET_FPS);

int main(int argc, char** argv)
{
	Game* game = new Game("Game", SCREEN_WIDTH, SCREEN_HEIGHT, 0); // Initializing of all game stuffs is happening inside

	unsigned long long int timeBeforeGameRendered, timeAfterGameRendered; // Two timers, created to be used in limiting frame rate, one of them will point to moment before game is rendered, second will point to moment after game is rendered and by subtracting these two numbers we can count time of game render(frameTime)
	int frameTime;

	while (game->isGameRunning())
	{

		timeBeforeGameRendered = SDL_GetTicks();
		game->HandleEvents();
		game->Update();
		game->Render();
		timeAfterGameRendered = SDL_GetTicks();

		frameTime = timeAfterGameRendered - timeBeforeGameRendered; // counting time of 1 frame
		if (frameTime < TARGET_FRAME_TIME)
			SDL_Delay(TARGET_FRAME_TIME - frameTime);
	}

	delete game; // Cleaning of all game stuffs is happening inside

	return 0;
}