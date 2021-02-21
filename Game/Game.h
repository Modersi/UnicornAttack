#pragma once

#include "../SDL2/include/SDL.h"
#include "../SDL2/include/SDL_main.h"
#include "../SDL2/include/SDL_ttf.h"
#include "../Box2D/include/box2d.h"

#include "iostream"
#include "string"
#include "sstream"
#include <vector>


class Unicorn;
class GameTimer;
class Map;

#define SCREEN_WIDTH			1280
#define SCREEN_HEIGHT			720

#define GROUND_Y	550

#define GAME_SPEED		5
#define DASH_DISTANCE	300

#define CONRTOL_MOVE_RIGHT			SDLK_RIGHT
#define CONRTOL_MOVE_LEFT			SDLK_LEFT
#define CONRTOL_JUMP				SDLK_SPACE
#define CONRTOL_NEW_GAME			SDLK_n
#define CONRTOL_CHANGE_GAME_MODE	SDLK_d
#define CONRTOL_GAME_QUIT			SDLK_ESCAPE
#define CONRTOL_DASH				SDLK_x



class Game
{
public:
	// Default constructor
	Game();

	// Constructor where we initialize game stuffs
	Game(const char* title, int width, int height, bool isFullscreen);

	// Handling of events
	void handleEvents();

	// This is where we updating our game data
	void update();

	// This is where we adding stuff to render
	void render();

	// Here we are restarting our game
	void restart();

	// Destructor where we deleting all SDL object and cleaning memory
	~Game();

	// Return game state
	inline bool isGameRunning() { return isRunning; }

	// Return game mode
	inline bool isAutoGameMode() { return autoGameMode; }

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static Unicorn* unicorn;
	static Map* map;
	static bool autoGameMode; // Variable that show is our game running in auto mode(true) on no(false)
	static GameTimer* gameTimer; // Variable of timer class

private:

	bool isRunning; // Variable that show is our game is running
	SDL_Window* window; // The window we will be rendering to 
	
};
