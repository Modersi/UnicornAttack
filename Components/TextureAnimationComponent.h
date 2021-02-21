#pragma once

#include "Game.h"

struct TextureAnimationComponent
{
	TextureAnimationComponent();
	TextureAnimationComponent(std::string animationSheetPath, int animationSpeed, int frameWidth, int frameHeight, bool isEndless = false);
	~TextureAnimationComponent();

	SDL_Surface* getSurfaceWithCurrentFrame();

	bool isEndless;
	int animationSpeed;
	int frameWidth, frameHeight;
	SDL_Rect currentFrameRectangle;
	SDL_Surface* animationSheet;
};