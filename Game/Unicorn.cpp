#include "Unicorn.h"
					 
Unicorn::Unicorn() : 
	/* Unicorn starting coordinates initializing */
	coordinates{ UNICORN_START_X_POS, GROUND_Y - RUNNING_ANIMATION_FRAME_HEIGHT },

	/* Initializing empty unicorn texture */
	unicornTexture{},

	/* All texture animation initializing */
	runningAnimation{ RUNNING_ANIMATION_SHEET_PATH, RUNNING_ANIMATION_SPEED, RUNNING_ANIMATION_FRAME_WIDTH, RUNNING_ANIMATION_FRAME_HEIGHT, true },
	jumpingAnimation{ JUMPING_ANIMATION_SHEET_PATH, JUMPING_ANIMATION_SPEED, JUMPING_ANIMATION_FRAME_WIDTH, JUMPING_ANIMATION_FRAME_HEIGHT, false },
	fallingAnimation{ FALLING_ANIMATION_SHEET_PATH, FALLING_ANIMATION_SPEED, FALLING_ANIMATION_FRAME_WIDTH, FALLING_ANIMATION_FRAME_HEIGHT, false },
	dashingAnimation{ DASHING_ANIMATION_SHEET_PATH, DASHING_ANIMATION_SPEED, DASHING_ANIMATION_FRAME_WIDTH, DASHING_ANIMATION_FRAME_HEIGHT, false },

	/*Timers initialization */
	lastJumpTimer{},
	lastDashTimer{}
{
	/* Set current texture animation, let it be running animation at begin */
	unicornTexture = runningAnimation;
}

void Unicorn::HandleEvents(SDL_Event* event)
{
	switch (Game::event.key.keysym.sym)
	{
	// Jump //
	case CONRTOL_JUMP:
		if (Game::unicorn->unicornJumpState == UnicornJumpState::DID_NOT_JUMPED)
		{
			Game::unicorn->unicornJumpState = UnicornJumpState::JUMPED;
			Game::unicorn->lastDashTimer.Restart();
			break;
		}
		else if (Game::unicorn->unicornJumpState == UnicornJumpState::JUMPED)
		{
			Game::unicorn->unicornJumpState = UnicornJumpState::DOUBLE_JUMPED;
			Game::unicorn->lastDashTimer.Restart();
			break;
		}
		break;

	// Move right //
	case CONRTOL_MOVE_RIGHT:
		//if((!Game::map->CheckCollizionFromRight() || Game::unicorn->unicornState == ON_BLOCK) && Game::autoGameMode == false)
			Game::map->moveMapLeft(GAME_SPEED);
		break;

	// Move left //
	case CONRTOL_MOVE_LEFT:
		//if ((!Game::map->CheckCollizionFromLeft() || Game::unicorn->unicornState == ON_BLOCK) && Game::autoGameMode == false)
			Game::map->moveMapRight(GAME_SPEED);
		break;

	// Dash //
	case CONRTOL_DASH:
		//if (!Game::map->CheckCollizionFromRight())
		{
			Game::unicorn->unicornState = UnicornState::DASHING;
			Game::unicorn->lastDashTimer.Restart();
			Game::map->moveMapLeft(DASH_DISTANCE);

			if (Game::unicorn->unicornJumpState == UnicornJumpState::DOUBLE_JUMPED)
				Game::unicorn->unicornJumpState = UnicornJumpState::JUMPED;
		}
		break;
	default:
		break;
	}
}

void Unicorn::Update()
{

	// Jumping
	if ( (Game::unicorn->unicornJumpState == UnicornJumpState::JUMPED || Game::unicorn->unicornJumpState == UnicornJumpState::DOUBLE_JUMPED)
	   && Game::unicorn->lastJumpTimer.GetTimeInSeconds() < 3)
	{
		Game::unicorn->coordinates.yPosition -= 15;
		Game::unicorn->unicornState = UnicornState::JUMPING;
	}

	if (Game::unicorn->lastDashTimer.GetTimeInSeconds() < 2)
	{
		Game::unicorn->unicornState = UnicornState::DASHING;
	}

	if (Game::unicorn->lastJumpTimer.GetTimeInSeconds() > 3 && Game::unicorn->lastDashTimer.GetTimeInSeconds() > 2)
	{
		Game::unicorn->unicornState = UnicornState::FALLING;
	}


	//------- Unicorn state check -------//

	// Falling check
	//if (Game::map->CheckCollizionWithGround())
	/*{
		Game::unicorn->unicornJumpState = DID_NOT_JUMPED;
		unicornState = ON_GROUND;
	}

	//else if (Game::map->CheckCollizionFromDown())
	{
		Game::unicorn->unicornJumpState = DID_NOT_JUMPED;
		unicornState = ON_BLOCK;
	}	*/

	//------- Unicorn moving -------//

	//if ((!Game::map->CheckCollizionFromRight() || Game::unicorn->unicornState == ON_BLOCK) && Game::autoGameMode == true) // Check if there is no collizion from right, if unicorn is staying on ground and if auto game mode is turned on
	/*	Game::map->moveMapLeft(GAME_SPEED + (Game::gameTimer->timer.GetTimeInSeconds() / 100));

	if (Game::unicorn->unicornState == FALLING) // Check if unicron  is falling
		Game::unicorn->coordinates.yPosition += UNICORN_FALLING_SPEED;*/

	//------- Unicorn animations doing -------//

	/*unsigned int lastTime = 0, currentTime = SDL_GetTicks();
	if (currentTime > lastTime + 3000) 
	{

		std::cout << "Unicorn state: " << Game::unicorn->unicornState << "Animation state: " << Game::unicorn->unicornAnimationState << std::endl;

		switch (Game::unicorn->unicornState)
		{
		case ON_GROUND:
			unicornTexture.setAnimation(runningAnimation);
			break;

		case ON_BLOCK:
			unicornTexture.setAnimation(runningAnimation);
			break;

		case FALLING:
			unicornTexture.setAnimation(fallingAnimation);
			break;

		case JUMPING:
			unicornTexture.setAnimation(jumpingAnimation);
			break;

		case DASHING:
			unicornTexture.setAnimation(dashingAnimation);
			break;

		default:
			break;
		}
		
		lastTime = currentTime;
	}*/

	unicornTexture = runningAnimation;

	/* All animation update (move current animation frame to next step) */
	runningAnimation.Update();
	jumpingAnimation.Update();
	fallingAnimation.Update();
	dashingAnimation.Update();
}

void Unicorn::Render()
{
	SDL_Rect renderRectangle = { coordinates.xPosition, coordinates.yPosition, unicornTexture.textureWidth, unicornTexture.textureHeight };
	SDL_RenderCopy(Game::renderer, unicornTexture.texture, NULL, &renderRectangle);
}

void Unicorn::Restart()
{
	coordinates.Restart();
}

Unicorn::~Unicorn()
{
	unicornTexture.DestroyTexture();
	runningAnimation.DestroyTextureAnimation();
	jumpingAnimation.DestroyTextureAnimation();
	fallingAnimation.DestroyTextureAnimation();
	dashingAnimation.DestroyTextureAnimation();
}
