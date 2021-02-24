#include "TextureAnimationComponent.h"

TextureAnimationComponent::TextureAnimationComponent() : 
	animationSheet{},
	currentFrameRectangle{ 0, 0, 0, 0 },
	frameWidth{ 0 },
	frameHeight{ 0 },
	animationSpeed{ 0 },
	isEndless{ false } 
{}

TextureAnimationComponent::TextureAnimationComponent(std::string animationSheetPath, int animationSpeed, int frameWidth, int frameHeight, bool isEndless) :
	animationSpeed{ animationSpeed },
	frameWidth{ frameWidth },
	frameHeight{ frameHeight },
	isEndless{ isEndless },
	currentFrameRectangle{ 0, 0, frameWidth, frameHeight }
{
	/* Creating an animation sheet surface from picture, check is everything is okay */
	animationSheet = SDL_LoadBMP(animationSheetPath.c_str());
	if (animationSheet == NULL)
		std::cout << "TextureAnimationComponent constructor error: SDL_LoadBMP = NULL" << std::endl;
}

void TextureAnimationComponent::Update()
{
	/* Check if animation is on last frame && If animation is endless */
	if (currentFrameRectangle.x == animationSheet->w - frameWidth && isEndless)
		currentFrameRectangle.x = 0; // Set animation frame to begin

	/* Check if animation not is on last frame */
	if (currentFrameRectangle.x < animationSheet->w - frameWidth)
		currentFrameRectangle.x += frameWidth; // Moving animation frame forward
}

void TextureAnimationComponent::DestroyTextureAnimation()
{
	/* Destroying surface data */
	SDL_FreeSurface(animationSheet);
}

SDL_Surface* TextureAnimationComponent::getSurfaceWithCurrentFrame() const
{
	SDL_Surface* currentFrameSurface = SDL_CreateRGBSurface(NULL, frameWidth, frameHeight, 24, 0, 0, 0, 0);

	/* Copying animation frame from animation sheet to surface, and check is everything ok */
	//SDL_BlitSurface(animationSheet, &currentFrameRectangle, currentFrameSurface, &currentFrameSurfaceRectangle);
	if(SDL_BlitSurface(animationSheet, &currentFrameRectangle, currentFrameSurface, NULL) == -1)
		std::cout << "SDL_BlitSurface error: " << SDL_GetError() << std::endl;

	return currentFrameSurface;
}
