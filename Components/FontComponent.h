#pragma once

#include "../Game/Game.h"

constexpr auto DEFAULT_FONT_FILE_PATH	= "Source/Fonts/OpenSans-Regular.ttf";
constexpr auto DEFAULT_FONT_SIZE		= 60;

struct FontComponent
{
	FontComponent();
	FontComponent(int fontSize, std::string fontFilePath);
	void DestroyFont();

	void DrawText(std::string text, int xPositon, int yPosition, SDL_Color fontColor = { 0, 0, 0, 0 });
	
	TTF_Font* font;
};
