#pragma once

#include "SDL.h"
#include "SDL_main.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "box2d.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <random>


class Camera;
class Unicorn;
class GameTimer;
class Map;
class ContactListener;

constexpr auto SCREEN_WIDTH	 = 1280;
constexpr auto SCREEN_HEIGHT = 720;

//**  Controls constants  **//
constexpr auto CONRTOL_JUMP				= SDLK_SPACE;
constexpr auto CONRTOL_NEW_GAME			= SDLK_n;
constexpr auto CONRTOL_CHANGE_GAME_MODE	= SDLK_d;
constexpr auto CONRTOL_GAME_QUIT		= SDLK_ESCAPE;
constexpr auto CONRTOL_DASH				= SDLK_x;

//**  Constants for Box2D  **//
constexpr auto TIME_STEP			= (1.0f / 60.0f);
constexpr auto VELOCITY_ITERATONS	= 6;
constexpr auto POSITION_ITERATONS	= 6;
constexpr auto WORLD_SCALING		= 0.01f; // Scaling for Box2D world. Example: from entity with height 175px make 1.75m Box2D entity

//**  Functions needed to convert coordinates systems (Pixels from SDL to meters from Box2D and backward)  **//
inline constexpr auto PIXELS_TO_METERS(const int &pixels)	{ return static_cast<float>(pixels * WORLD_SCALING); }
inline constexpr auto METERS_TO_PIXELS(const float &meters) { return static_cast<int>(meters / WORLD_SCALING); }


class Game
{
public:
	// Constructor where we initialize game stuffs
	Game(const char* title, int width, int height, bool isFullscreen);

	// Destructor where we deleting all SDL object and cleaning memory
	~Game();

	// Handling of events
	void HandleEvents();

	// This is where we updating our game data
	void Update();

	// This is where we adding stuff to render
	void Render();

	// Here we are restarting our game
	void Restart();

	// Return game state
	inline bool isGameRunning() { return isRunning; }

	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Event* event;
	static Camera* camera;
	static b2World* box2DWorld;
	static ContactListener* contactListener;

private:
	Unicorn* unicorn;
	Map* map;
	GameTimer* gameTimer;

	bool isRunning;
};
