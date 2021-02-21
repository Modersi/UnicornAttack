#include "TextureAnimationComponent.h"

TextureAnimationComponent::TextureAnimationComponent() : animationSheet(nullptr), currentFrameRectangle({ 0, 0, 0, 0 }), frameWidth(0),
														 frameHeight(0), animationSpeed(0), isEndless(false) {}

TextureAnimationComponent::TextureAnimationComponent(std::string animationSheetPath, int animationSpeed, int frameWidth, int frameHeight, bool isEndless) :
													animationSpeed(animationSpeed), frameWidth(frameWidth), frameHeight(frameHeight), isEndless(isEndless)
{
	/* Creating an animation sheet surface from picture, check is everything is okay */
	animationSheet = SDL_LoadBMP(animationSheetPath.c_str());
	if (animationSheet == NULL)
		std::cout << "TextureAnimationComponent constructor error: SDL_LoadBMP = NULL" << std::endl;

	/* Assigning a basic values for our current animation frame rectangle */
	currentFrameRectangle = { 0, 0, frameWidth, frameHeight };
}

TextureAnimationComponent::~TextureAnimationComponent()
{
	/* Destroying surface data */
	SDL_FreeSurface(animationSheet);
}

SDL_Surface* TextureAnimationComponent::getSurfaceWithCurrentFrame()
{
	SDL_Surface* currentFrameSurface;

	/* Copying animation frame from animation sheet to surface, and check is everything ok */
	if(SDL_BlitSurface(animationSheet, &currentFrameRectangle, currentFrameSurface, NULL) == -1)
		std::cout << "TextureAnimationComponent getSurfaceWithCurrentFrame error: SDL_BlitSurface error: " << SDL_GetError() << std::endl;

	return currentFrameSurface;
}
