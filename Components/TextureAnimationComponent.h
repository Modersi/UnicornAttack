#pragma once

#include "../Game/Game.h"

struct TextureAnimationComponent
{
	TextureAnimationComponent();
	TextureAnimationComponent(std::string animationSheetPath, int animationSpeed, int frameWidth, int frameHeight, bool isEndless = false);
	~TextureAnimationComponent();

	void Update();

	SDL_Surface* getSurfaceWithCurrentFrame() const;

	bool isEndless;
	int animationSpeed;
	int frameWidth, frameHeight;
	SDL_Rect currentFrameRectangle;
	SDL_Surface* animationSheet;
};