#include "Unicorn.h"
					 
Unicorn::Unicorn() : 
//**  Unicorn start coordinates initialization  **//
	unicornCoordinates(UNICORN_START_X_POS, UNICORN_START_Y_POS),

//**  Initializing empty unicorn texture **//
	unicornTexture(),

//**  Counters zero initialization **//
	jumpCounter(),
	dashCounter(),

//**  All texture animation initialization  **//
	runningAnimation( RUNNING_ANIMATION_SHEET_PATH, RUNNING_ANIMATION_FRAME_WIDTH, RUNNING_ANIMATION_FRAME_HEIGHT, true ),
	jumpingAnimation( JUMPING_ANIMATION_SHEET_PATH, JUMPING_ANIMATION_FRAME_WIDTH, JUMPING_ANIMATION_FRAME_HEIGHT, false ),
	fallingAnimation( FALLING_ANIMATION_SHEET_PATH, FALLING_ANIMATION_FRAME_WIDTH, FALLING_ANIMATION_FRAME_HEIGHT, false ),
	dashingAnimation( DASHING_ANIMATION_SHEET_PATH, DASHING_ANIMATION_FRAME_WIDTH, DASHING_ANIMATION_FRAME_HEIGHT, false )
{
//** Setting up current texture animation, let it be running animation at begin **//
	unicornTexture = runningAnimation;

//**  Setting up unicorn Box2D collision body  **//

	/* Setting up unicorn body form */
	b2PolygonShape bodyShape;
	bodyShape.SetAsBox(PIXELS_TO_METERS(unicornTexture.textureWidth), PIXELS_TO_METERS(unicornTexture.textureHeight));

	/* Setting up fixture parameters */
	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &bodyShape;
	fixtureDefinition.density = 1.0f;
	fixtureDefinition.friction = 0.0f;

	/* Setting up unicorn body type and position */
	b2BodyDef bodyDefinition;
	bodyDefinition.type = b2_dynamicBody;
	bodyDefinition.position.Set(PIXELS_TO_METERS(unicornCoordinates.xPosition), -PIXELS_TO_METERS(unicornCoordinates.yPosition));
	bodyDefinition.fixedRotation = true;
	bodyDefinition.userData.pointer = reinterpret_cast<uintptr_t>("Unicorn");

	/* Adding unicorn collision body to our game world and setting a fixture */
	unicornCollisionBody = Game::box2DWorld->CreateBody(&bodyDefinition);
	unicornCollisionBody->CreateFixture(&fixtureDefinition);
}

void Unicorn::HandleEvents(SDL_Event* event)
{
//**  JUMP  **//
	if (Game::event->key.keysym.sym == CONRTOL_JUMP)
		if (jumpCounter < MAX_JUMPS)
		{
			/* Maek Unicorn collision body jump */
			unicornCollisionBody->SetLinearVelocity(b2Vec2(unicornCollisionBody->GetLinearVelocity().x, 0.0f)); // Setting unicorn falling speed to 0 to prevent strange jump
			unicornCollisionBody->ApplyLinearImpulseToCenter(b2Vec2(0.0f, 100.0f), true);

			/* Increase count of jumps */
			jumpCounter++;
		}

//**  DASH  **//
	if (Game::event->key.keysym.sym == CONRTOL_DASH)
		if (dashCounter < MAX_DASHES)
		{
			unicornCollisionBody->ApplyLinearImpulseToCenter(b2Vec2(100.0f, 0.0f), true);
			dashCounter++;
		}

}

void Unicorn::Update()
{
	std::cout << "LinearVelocity.y = " << unicornCollisionBody->GetLinearVelocity().y << std::endl;

//**  Unicorn animations handling **//

	/* Set running animation if unicorn is on ground, and reset jumping and falling animations  */
	if (Game::contactListener->unicornTouchingGround == true)
	{
		unicornTexture = runningAnimation;

		fallingAnimation.Restart();
		jumpingAnimation.Restart();
	}

	/* Set falling animation if unicorn's speed less then 0 (if it's falling) */
	if (unicornCollisionBody->GetLinearVelocity().y < -0.1f) // Using -0.1 istead of 0.0 to prevent some shitty bugs
	{
		unicornTexture = fallingAnimation;
		jumpingAnimation.Restart();
	}

	/* Set jumping animation if unicorn's speed more then 0 (if it's jumping) */
	if (unicornCollisionBody->GetLinearVelocity().y > 0.1f)  // Using 0.1 istead of 0.0 to prevent some shitty bugs
	{
		unicornTexture = jumpingAnimation;

		/* Restarting falling animation to play it from begin when it will start to fall after jump */
		fallingAnimation.Restart();
	}

	/*  All animations update (move animation current frame to next step) */
	UpdateAllAnimations();
	
//** Unicorn data update **//

	/*  Make Unicorn run to the right */
	if(unicornCollisionBody->GetLinearVelocity().x < 25.0f)
		unicornCollisionBody->ApplyForceToCenter(b2Vec2(5.0f, 0.0f), true);

	/*  Unicorn coordinates updating to his collision body coordinates */
	unicornCoordinates = unicornCollisionBody->GetPosition();

	/* Reseting dash and jump counters when Unicorn touching ground */
	if (Game::contactListener->unicornTouchingGround == true)
		dashCounter = jumpCounter = 0;

//**  Here we follow unicorn with our camera, and setting unicorn at screen center **//

	Game::camera->SetPosition(unicornCoordinates.xPosition, unicornCoordinates.yPosition - (SCREEN_HEIGHT / 2) + 200);
}

void Unicorn::Render()
{
	SDL_Rect renderRectangle = { unicornCoordinates.xPosition - Game::camera->GetXPosition(),
								 unicornCoordinates.yPosition - Game::camera->GetYPosition(),
								 unicornTexture.textureWidth,
								 unicornTexture.textureHeight };

	SDL_RenderCopy(Game::renderer, unicornTexture.texture, NULL, &renderRectangle);
}

void Unicorn::Restart()
{
	unicornCoordinates.Restart();
	unicornCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(unicornCoordinates.startXPosition), -PIXELS_TO_METERS(unicornCoordinates.startYPosition)), 0.0f);
	unicornCollisionBody->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

void Unicorn::UpdateAllAnimations()
{
	runningAnimation.Update();
	jumpingAnimation.Update();
	fallingAnimation.Update();
	dashingAnimation.Update();
}

Unicorn::~Unicorn()
{
	unicornTexture.DestroyTexture();

	runningAnimation.DestroyTextureAnimation();
	jumpingAnimation.DestroyTextureAnimation();
	fallingAnimation.DestroyTextureAnimation();
	dashingAnimation.DestroyTextureAnimation(); 
}
