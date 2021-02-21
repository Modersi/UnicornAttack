#include "TextureComponent.h"

TextureComponent::TextureComponent() : texture(nullptr), textureWidth(0), textureHeight(0) {}

TextureComponent::TextureComponent(std::string texturePath, int textureWidth, int textureHeight)
	: textureWidth(textureWidth), textureHeight(textureHeight) 
{

	/* Creating a surface from picture, check is everything is okay */
	SDL_Surface* tempSurface = SDL_LoadBMP(texturePath.c_str());
	if (tempSurface == NULL)
		std::cout << "TextureComponent constructor error: SDL_LoadBMP = NULL" << std::endl;

	/* Creating a texture from surface */
	texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	if (texture == NULL)
		std::cout << "TextureComponent constructor error: SDL_CreateTextureFromSurface = NULL" << std::endl;

	/* Destroying temporary surface data */
	SDL_FreeSurface(tempSurface);
}

TextureComponent::~TextureComponent()
{
	/* Destroying texture data */
	SDL_DestroyTexture(texture);
}

void TextureComponent::setAnimation(TextureAnimationComponent animation)
{
	/* Destroying previous texture data to replace it with new one */
	SDL_DestroyTexture(texture);


	/* Creating a surface with current animation frame and assign it to texture */
	SDL_Surface* surfaceWithCurrentFrame = animation.getSurfaceWithCurrentFrame();
	texture = SDL_CreateTextureFromSurface(Game::renderer, surfaceWithCurrentFrame);
	SDL_FreeSurface(surfaceWithCurrentFrame);

	/* Check if animation is on last frame && If animation is endless */
	if (animation.currentFrameRectangle.x == animation.animationSheet->w - animation.frameWidth && animation.isEndless)
		animation.currentFrameRectangle.x = 0; // Set animation frame to begin

	/* Check if animation not is on last frame */
	if (animation.currentFrameRectangle.x <= animation.animationSheet->w - animation.frameWidth)
		animation.currentFrameRectangle.x += animation.frameWidth; // Moving animation frame forward
}
