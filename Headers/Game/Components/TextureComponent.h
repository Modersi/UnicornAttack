#pragma once

#include "Game.h"
#include "Components/TextureAnimationComponent.h"

struct TextureComponent
{
	TextureComponent();
	TextureComponent(std::string texturePath, int textureWidth, int textureHeight);
	TextureComponent(SDL_Surface* surfaceWithTexture);
	void DestroyTexture();

	void operator = (const TextureAnimationComponent& animation);

	SDL_Texture* texture;
	int textureWidth, textureHeight;
};