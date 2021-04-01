#include "TextureAnimationComponent.h"

TextureAnimationComponent::TextureAnimationComponent() : 
	isEndless(false),
	currentFrameRectangle{ 0, 0, 0, 0 },
	animationSheet(nullptr)
{}

TextureAnimationComponent::TextureAnimationComponent(std::string animationSheetPath, int frameWidth, int frameHeight, bool isEndless) :
	isEndless(isEndless),
	currentFrameRectangle{ 0, 0, frameWidth, frameHeight }
{
	/* Creating an animation sheet surface from picture, check is everything okay */
	animationSheet = IMG_Load(animationSheetPath.c_str());
	if (animationSheet == NULL)
		std::cout << "TextureAnimationComponent constructor error: SDL_LoadBMP = NULL" << std::endl;
}

void TextureAnimationComponent::Update()
{
	/* Check if animation is on last frame && If animation is endless */
	if (currentFrameRectangle.x == animationSheet->w -  currentFrameRectangle.w && isEndless)
		currentFrameRectangle.x = 0; // Set animation frame to begin

	/* Check if animation is not on last frame */
	if (currentFrameRectangle.x < animationSheet->w - currentFrameRectangle.w)
		currentFrameRectangle.x += currentFrameRectangle.w; // Moving animation frame forward
}

void TextureAnimationComponent::Restart()
{
	currentFrameRectangle.x = currentFrameRectangle.y = 0;
}

void TextureAnimationComponent::DestroyTextureAnimation()
{
	/* Destroying surface data */
	SDL_FreeSurface(animationSheet);
}

SDL_Surface* TextureAnimationComponent::getSurfaceWithCurrentFrame() const
{
	/* Creating a new transparent surface */
	SDL_Surface* currentFrameSurface = SDL_CreateRGBSurface(NULL, currentFrameRectangle.w, currentFrameRectangle.h, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

	/* Copying animation frame from animation sheet to new surface, and check is everything okay */
	if(SDL_BlitSurface(animationSheet, &currentFrameRectangle, currentFrameSurface, NULL) == -1)
		std::cout << "SDL_BlitSurface error: " << SDL_GetError() << std::endl;

	return currentFrameSurface;
}
