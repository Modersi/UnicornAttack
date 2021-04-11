#pragma once

#include "Game.h"

struct TextureAnimationComponent
{
	TextureAnimationComponent();
	TextureAnimationComponent(std::string animationSheetPath, int frameWidth, int frameHeight, bool isEndless = false);
	void DestroyTextureAnimation();

	void Update();

	void Restart();

	SDL_Surface* getSurfaceWithCurrentFrame() const;

	bool isEndless;
	SDL_Rect currentFrameRectangle;
	SDL_Surface* animationSheet;
};