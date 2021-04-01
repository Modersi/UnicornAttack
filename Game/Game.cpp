#include "Game.h"
#include "Unicorn.h"
#include "../Map/Map.h"
#include "GameTimer.h"
#include "Camera.h"
#include "ContactListener.h"


SDL_Window* Game::window = nullptr;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event* Game::event = nullptr;
Camera* Game::camera = nullptr;
b2World* Game::box2DWorld = nullptr;
ContactListener* Game::contactListener = nullptr;

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

	// Initializing SDL IMG
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {	// If initialization went wrong write error to console than stop the game
		SDL_Quit();
		printf("SDL_IMG_Init error: %s\n", TTF_GetError());
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

	Game::isRunning = true;

	Game::contactListener = new ContactListener();

	Game::box2DWorld = new b2World(b2Vec2(0.0f, -25.0f));
	Game::box2DWorld->SetContactListener(contactListener);

	Game::event = new SDL_Event();

	Game::unicorn = new Unicorn();

	Game::camera = new Camera(0, 0);

	Game::map = new Map();

	Game::gameTimer = new GameTimer();

}

void Game::HandleEvents()
{
	SDL_PollEvent(Game::event);

	// SDL SHUTDOWN //
	if (Game::event->type == SDL_QUIT)
	{
		Game::isRunning = false;
	}

	// KEY PRESSED ///
	if (Game::event->type == SDL_KEYDOWN)
	{
		switch (Game::event->key.keysym.sym)
		{
		//-----------  Game handling  -----------//

			// Quit from game //
			case CONRTOL_GAME_QUIT:
				Game::isRunning = false;
				break;

			// New game //
			case CONRTOL_NEW_GAME:
				Restart();
				break;

		//-----------  Unicorn handling  -----------//

			// Jump //
			case CONRTOL_JUMP:
				Game::unicorn->HandleEvents(event);
				break;		 
							 
			// Dash //		 
			case CONRTOL_DASH:
				Game::unicorn->HandleEvents(event);
				break;

			default:
				break;
		}
	}
}

void Game::Update()
{
	Game::box2DWorld->Step(TIME_STEP, VELOCITY_ITERATONS, POSITION_ITERATONS);
	Game::unicorn->Update();
	Game::map->Update();
}

void Game::Render()
{
	SDL_RenderClear(Game::renderer);
	
	Game::map->Render();
	Game::unicorn->Render();
	Game::gameTimer->Render();

	SDL_RenderPresent(Game::renderer);
}

void Game::Restart()
{
	Game::unicorn->Restart();
	Game::gameTimer->Restart();
	Game::map->Restart();
}
 
Game::~Game()
{
	delete Game::unicorn;
	Game::unicorn = nullptr;

	delete Game::event;
	Game::event = nullptr;

	delete Game::map;
	Game::map = nullptr;

	delete Game::gameTimer;
	Game::gameTimer = nullptr;

	delete Game::camera;
	Game::camera = nullptr;

	delete Game::contactListener;
	Game::contactListener = nullptr;

	Game::box2DWorld->~b2World();
	box2DWorld = nullptr;

	SDL_DestroyWindow(Game::window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
}
