#pragma once

#include "../Game/Game.h"
#include "TextureAnimationComponent.h"

struct TextureComponent
{
	TextureComponent();
	TextureComponent(std::string texturePath, int textureWidth, int textureHeight);
	~TextureComponent();

	void setAnimation (TextureAnimationComponent animation);

	SDL_Texture* texture;
	int textureWidth, textureHeight;
};