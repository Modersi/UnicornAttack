#include "Game/Game.h"

#define TARGET_FPS				60
#define TARGET_FRAME_TIME		(1000 / TARGET_FPS)

int main(int argc, char** argv)
{
	Game* game = new Game("Game", SCREEN_WIDTH, SCREEN_HEIGHT, 0); // Initializing of all game stuffs is happening inside

	unsigned long long int timeBeforeGameRendered, timeAfterGameRendered; // Two timers, created to be used in limiting frame rate system, one of them will point to moment before game is rendered, second will point to moment after game is rendered and by subtracting these two numbers we can count time of game render(frameTime)
	int frameTime, currentFPS;

	while (game->isGameRunning())
	{

		timeBeforeGameRendered = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		timeAfterGameRendered = SDL_GetTicks();



		frameTime = timeAfterGameRendered - timeBeforeGameRendered; // counting time of 1 frame
		if (frameTime < TARGET_FRAME_TIME)
			SDL_Delay(TARGET_FRAME_TIME - frameTime);
	}

	delete game; // Cleaning of all game stuffs is happening inside

	return 0;
}