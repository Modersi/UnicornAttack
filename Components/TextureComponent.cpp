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

TextureComponent::~TextureComponent()
{
	/* Destroying texture data */
	SDL_DestroyTexture(texture);
}

TextureComponent* TextureComponent::operator = (const TextureAnimationComponent& animation)
{
	/* Destroying previous texture data to replace it with new one */
	this->~TextureComponent();

	/* Creating a surface with current animation frame and create a new texture object with it */
	SDL_Surface* surfaceWithCurrentFrame = animation.getSurfaceWithCurrentFrame();
	TextureComponent* newTexture = new TextureComponent(surfaceWithCurrentFrame);
	SDL_FreeSurface(surfaceWithCurrentFrame);
	
	return newTexture;
}
