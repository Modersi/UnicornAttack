#include "Components/TextureComponent.h"

TextureComponent::TextureComponent() :
	texture(),
	textureWidth(0),
	textureHeight(0) 
{}

TextureComponent::TextureComponent(std::string texturePath, int textureWidth, int textureHeight) :
	textureWidth(textureWidth),
	textureHeight(textureHeight)  
{
	/* Creating a surface from picture, check is everything is okay */
	SDL_Surface* tempSurface = IMG_Load(texturePath.c_str());
	if (tempSurface == NULL)
		std::cout << "TextureComponent constructor error: SDL_LoadBMP = NULL" << std::endl;

	/* Creating a texture from surface */
	texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	if (texture == NULL)
		std::cout << "TextureComponent constructor error: SDL_CreateTextureFromSurface = NULL" << std::endl;

	/* Destroying temporary surface */
	SDL_FreeSurface(tempSurface);
}

TextureComponent::TextureComponent(SDL_Surface* surfaceWithTexture)
{
	/* Creating a texture from surface */
	texture = SDL_CreateTextureFromSurface(Game::renderer, surfaceWithTexture);

	/* Set texture width and height */
	textureWidth = surfaceWithTexture->w;
	textureHeight = surfaceWithTexture->h;

	/* Error if something went wrong */
	if (texture == NULL)
		std::cout << "TextureComponent constructor error: SDL_CreateTextureFromSurface = NULL" << std::endl;
}

void TextureComponent::operator = (const TextureAnimationComponent& animation)
{
	/* Destroying previous texture to replace it with new one */
	this->DestroyTexture();

	/* Creating a surface with current animation frame */
	SDL_Surface* surfaceWithCurrentFrame = animation.getSurfaceWithCurrentFrame();

	/* Creating a new texture from surface with animation frame and setting texture width and height */
	this->texture = SDL_CreateTextureFromSurface(Game::renderer, surfaceWithCurrentFrame);
	this->textureWidth = surfaceWithCurrentFrame->w;
	this->textureHeight = surfaceWithCurrentFrame->h;

	/* Destroying temporary surface */
	SDL_FreeSurface(surfaceWithCurrentFrame);
}

void TextureComponent::DestroyTexture()
{
	SDL_DestroyTexture(texture);
}
