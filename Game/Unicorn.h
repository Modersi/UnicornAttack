#pragma once

#include "GameTimer.h"
#include "Camera.h"
#include "ContactListener.h"
#include "../Map/Map.h"
#include "../Components/CoordinatesComponent.h"
#include "../Components/TextureComponent.h"

constexpr auto RUNNING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornRunningAnimationSheet.png";
constexpr auto RUNNING_ANIMATION_FRAME_HEIGHT = 92;
constexpr auto RUNNING_ANIMATION_FRAME_WIDTH =	175;

constexpr auto JUMPING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornJumpingAnimationSheet.png ";
constexpr auto JUMPING_ANIMATION_FRAME_HEIGHT = 133;
constexpr auto JUMPING_ANIMATION_FRAME_WIDTH =	162;

constexpr auto FALLING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornFallingAnimationSheet.png ";
constexpr auto FALLING_ANIMATION_FRAME_HEIGHT = 133;
constexpr auto FALLING_ANIMATION_FRAME_WIDTH =	162;

constexpr auto DASHING_ANIMATION_SHEET_PATH =	"Source/Textures/UnicornDashingAnimationSheet.png";
constexpr auto DASHING_ANIMATION_FRAME_HEIGHT = 169;
constexpr auto DASHING_ANIMATION_FRAME_WIDTH =	480;

constexpr auto UNICORN_START_X_POS = -120;
constexpr auto UNICORN_START_Y_POS = 300;

constexpr auto MAX_JUMPS = 2;
constexpr auto MAX_DASHES = 1;


class Unicorn
{
	friend ContactListener;

public:
	Unicorn();
	~Unicorn();

	void HandleEvents(SDL_Event* event);

	void Update();

	void Render();

	void Restart();

private:

	void UpdateAllAnimations();

	/* Unicorn coordinates */
	CoordinatesComponent unicornCoordinates;

	/* Everything related to unicorn texture and animation */
	TextureComponent unicornTexture;
	TextureAnimationComponent runningAnimation, jumpingAnimation, fallingAnimation, dashingAnimation;

	/* Counters for dashing and jumping */
	short int jumpCounter, dashCounter;

	/* Unicorn collision body  */
	b2Body* unicornCollisionBody;
};