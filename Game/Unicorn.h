#pragma once

#include "GameTimer.h"
#include "../Map/Map.h"

#include "../Components/CoordinatesComponent.h"
#include "../Components/TextureComponent.h"

constexpr auto RUNNING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornRunningAnimationSheet.bmp";
constexpr auto RUNNING_ANIMATION_FRAME_HEIGHT = 92;
constexpr auto RUNNING_ANIMATION_FRAME_WIDTH =	175;
constexpr auto RUNNING_ANIMATION_SPEED =		5000;

constexpr auto JUMPING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornJumpingAnimationSheet.bmp";
constexpr auto JUMPING_ANIMATION_FRAME_HEIGHT = 123;
constexpr auto JUMPING_ANIMATION_FRAME_WIDTH =	175;
constexpr auto JUMPING_ANIMATION_SPEED =		10000;

constexpr auto FALLING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornFallingAnimationSheet.bmp";
constexpr auto FALLING_ANIMATION_FRAME_HEIGHT = 125;
constexpr auto FALLING_ANIMATION_FRAME_WIDTH =	175;
constexpr auto FALLING_ANIMATION_SPEED =		15000;

constexpr auto DASHING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornDashAnimationSheet.bmp";
constexpr auto DASHING_ANIMATION_FRAME_HEIGHT = 150;
constexpr auto DASHING_ANIMATION_FRAME_WIDTH =	400;
constexpr auto DASHING_ANIMATION_SPEED =		20000;

constexpr auto UNICORN_START_X_POS = 15;
constexpr auto UNICORN_START_Y_POS = 250;

constexpr auto UNICORN_JUMP_HEIGHT = 200;
constexpr auto UNICORN_FALLING_SPEED = 5;


class Unicorn
{
public:
	Unicorn();
	~Unicorn();

	enum class UnicornAnimationState : int 
	{
		FALLING_ANIMATION,
		RUNNING_ANIMATION,
		JUMPING_ANIMATION,
		DASHING_ANIMATION
	};

	enum class UnicornState : int 
	{
		FALLING,
		JUMPING,
		ON_GROUND,
		ON_BLOCK,
		DASHING
	};

	enum class UnicornJumpState : int 
	{
		DID_NOT_JUMPED,
		JUMPED,
		DOUBLE_JUMPED
	};

	void HandleEvents(SDL_Event* event);

	void Update();

	void Render();

	void Restart();

private:
	/* Coordinates */
	CoordinatesComponent coordinates;

	/* Everything related to unicorn texture and animation */
	TextureComponent unicornTexture;
	TextureAnimationComponent jumpingAnimation, fallingAnimation, runningAnimation, dashingAnimation;

	/* All posible enum's to describe state of unicorn */
	UnicornState unicornState;
	UnicornJumpState unicornJumpState;
	UnicornAnimationState unicornAnimationState;

	/* Timers which is counting how much time has passed from last jump and last dash  */
	TimerComponent lastJumpTimer;
	TimerComponent lastDashTimer;
};