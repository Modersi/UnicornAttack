#include "Game.h"
#include "Unicorn.h"
#include "Map.h"
#include "GameTimer.h"


SDL_Renderer* Game::renderer = nullptr;
Unicorn* Game::unicorn = nullptr;
SDL_Event Game::event;
Map* Game::map = nullptr;
bool Game::autoGameMode;
GameTimer* Game::gameTimer = nullptr;

Game::Game() {}

Game::Game(const char* title, int width, int height, bool isFullscreen)
{
	// Initializing SDL sybsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {	// If initialization went wrong write error to console than stop the game
		SDL_Quit();
		printf("SDL_Init error: %s\n", SDL_GetError());		
		isRunning = false;
	}

	// Initializing SDL TTF
	if (TTF_Init() != 0) {	// If initialization went wrong write error to console than stop the game
		SDL_Quit();
		printf("SDL_TTF_Init error: %s\n", TTF_GetError());
		isRunning = false;
	}

	// Initializing window and renderer
	int flags = (isFullscreen == true) ? SDL_WINDOW_FULLSCREEN : 0; // Define if we want fullscreen mode
	if (SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer) != 0) { // If creating went wrong write an error to console than stop the game
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		isRunning = false;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	isRunning = true;

	unicorn = new Unicorn();

	gameTimer = new GameTimer();

	map = new Map();

	autoGameMode = false;
}

void Game::handleEvents()
{
	SDL_PollEvent(&Game::event);

	// SDL SHUTDOWN //
	if (Game::event.type == SDL_QUIT)
	{
		isRunning = false;
	}

	// KEY PRESSED ///
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		//-----------  Game handling  -----------//

			// Quit from game //
			case CONRTOL_GAME_QUIT:
				isRunning = false;
				break;

			// New game //
			case CONRTOL_NEW_GAME:
				restart();
				break;

			// Change game mode //
			case CONRTOL_CHANGE_GAME_MODE:
				if (autoGameMode == false)
					autoGameMode = true;
				else
					autoGameMode = false;
				break;

		//-----------  Unicorn handling  -----------//

			// Move right //
			case CONRTOL_MOVE_RIGHT:
				Game::unicorn->HandleEvents(&event);
				break;

			// Move left //
			case CONRTOL_MOVE_LEFT:
				Game::unicorn->HandleEvents(&event);
				break;

			// Jump //
			case CONRTOL_JUMP:
				Game::unicorn->HandleEvents(&event);
				break;

			// Dash //
			case CONRTOL_DASH:
				Game::unicorn->HandleEvents(&event);
				break;

			default:
				break;
		}
	}
}

void Game::update()
{
	Game::unicorn->Update();
	Game::map->Update();
}

void Game::render()
{
	SDL_RenderClear(Game::renderer);
	
	Game::unicorn->Render();
	Game::gameTimer->Render();
	Game::map->Render();

	SDL_RenderPresent(Game::renderer);
}

void Game::restart()
{
	Game::unicorn->Restart();
	Game::gameTimer->Restart();
	Game::map->Restart();
}
 
Game::~Game()
{
	delete unicorn;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();

	printf("Game Cleaned\n");
}
