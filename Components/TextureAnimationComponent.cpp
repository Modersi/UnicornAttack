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

void TextureAnimationComponent::Update()
{
	/* Check if animation is on last frame && If animation is endless */
	if (currentFrameRectangle.x == animationSheet->w - frameWidth && isEndless)
		currentFrameRectangle.x = 0; // Set animation frame to begin

	/* Check if animation not is on last frame */
	if (currentFrameRectangle.x < animationSheet->w - frameWidth)
		currentFrameRectangle.x += frameWidth; // Moving animation frame forward
}

SDL_Surface* TextureAnimationComponent::getSurfaceWithCurrentFrame() const
{
	SDL_Surface* currentFrameSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, currentFrameRectangle.w, currentFrameRectangle.h, 24, 0, 0, 0, 0);
	if (currentFrameSurface == NULL)
		std::cout << "Pizda" << std::endl;
	SDL_Rect currentFrameSurfaceRectangle = currentFrameRectangle;
	/* Copying animation frame from animation sheet to surface, and check is everything ok */
	//SDL_BlitSurface(animationSheet, &currentFrameRectangle, currentFrameSurface, &currentFrameSurfaceRectangle);
	if(SDL_BlitSurface(animationSheet, &currentFrameRectangle, currentFrameSurface, NULL) == -1)
		std::cout << "TextureAnimationComponent getSurfaceWithCurrentFrame error: SDL_BlitSurface error: " << SDL_GetError() << std::endl;

	return currentFrameSurface;
}
