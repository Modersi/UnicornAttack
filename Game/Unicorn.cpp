#include "Unicorn.h"

Unicorn::Unicorn()
{
	unicornTexture = TextureComponent();

	/* Animation initialization */
	runningAnimation = TextureAnimationComponent(RUNNING_ANIMATION_SHEET_PATH, 3000, RUNNING_ANIMATION_FRAME_WIDTH, RUNNING_ANIMATION_FRAME_HEIGHT, true);
	jumpingAnimation = TextureAnimationComponent(JUMPING_ANIMATION_SHEET_PATH, 3000, JUMPING_ANIMATION_FRAME_WIDTH, JUMPING_ANIMATION_FRAME_HEIGHT, true);
	fallingAnimation = TextureAnimationComponent(FALLING_ANIMATION_SHEET_PATH, 3000, FALLING_ANIMATION_FRAME_WIDTH, FALLING_ANIMATION_FRAME_HEIGHT, true);
	dashingAnimation = TextureAnimationComponent(DASHING_ANIMATION_SHEET_PATH, 3000, DASHING_ANIMATION_FRAME_WIDTH, DASHING_ANIMATION_FRAME_HEIGHT, true);

	/* Set current texture animation, let it be running animation at begin */
	unicornTexture.setAnimation(runningAnimation);

	/* Initialize coordinates of unicorn */
	coordinates = CoordinatesComponent(UNICORN_START_X_POS, GROUND_Y - RUNNING_ANIMATION_FRAME_HEIGHT);
}

void Unicorn::HandleEvents(SDL_Event* event)
{
	switch (Game::event.key.keysym.sym)
	{
	// Jump //
	case CONRTOL_JUMP:
		if (Game::unicorn->unicornJumpState == DID_NOT_JUMPED)
		{
			Game::unicorn->unicornJumpState = JUMPED;
			Game::unicorn->lastJumpTime = SDL_GetTicks();
			break;
		}
		else if (Game::unicorn->unicornJumpState == JUMPED)
		{
			Game::unicorn->unicornJumpState = DOUBLE_JUMPED;
			Game::unicorn->lastJumpTime = SDL_GetTicks();
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
			Game::unicorn->unicornState = DASHING;
			Game::unicorn->lastDashTime = SDL_GetTicks();
			Game::map->moveMapLeft(DASH_DISTANCE);

			if (Game::unicorn->unicornJumpState == DOUBLE_JUMPED)
				Game::unicorn->unicornJumpState = JUMPED;
		}
			
		break;
	default:
		break;
	}
}

void Unicorn::Update()
{

	// Jumping
	if ((Game::unicorn->unicornJumpState == JUMPED || Game::unicorn->unicornJumpState == DOUBLE_JUMPED) && Game::unicorn->lastJumpTime + 300 > SDL_GetTicks())
	{
		Game::unicorn->coordinates.yPosition -= 15;
		Game::unicorn->unicornState = JUMPING;
	}

	if (Game::unicorn->lastDashTime + 500 > SDL_GetTicks())
	{
		Game::unicorn->unicornState = DASHING;
	}

	if (Game::unicorn->lastJumpTime + 300 < SDL_GetTicks() && Game::unicorn->lastDashTime + 500 < SDL_GetTicks())
	{
		Game::unicorn->unicornState = FALLING;
	}


	//------- Unicorn state check -------//

	// Falling check
	//if (Game::map->CheckCollizionWithGround())
	{
		Game::unicorn->unicornJumpState = DID_NOT_JUMPED;
		unicornState = ON_GROUND;
	}

	//else if (Game::map->CheckCollizionFromDown())
	{
		Game::unicorn->unicornJumpState = DID_NOT_JUMPED;
		unicornState = ON_BLOCK;
	}	

	//------- Unicorn moving -------//

	//if ((!Game::map->CheckCollizionFromRight() || Game::unicorn->unicornState == ON_BLOCK) && Game::autoGameMode == true) // Check if there is no collizion from right, if unicorn is staying on ground and if auto game mode is turned on
		Game::map->moveMapLeft(GAME_SPEED + (Game::gameTimer->timer.GetTimeInSeconds() / 100));

	if (Game::unicorn->unicornState == FALLING) // Check if unicron  is falling
		Game::unicorn->coordinates.yPosition += UNICORN_FALLING_SPEED;

	//------- Unicorn animations doing -------//

	unsigned int lastTime = 0, currentTime = SDL_GetTicks();
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
	}
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
	//SDL_DestroyTexture(unicornTexture.texture);
}
