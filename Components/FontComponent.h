#pragma once

#include "../Game/Game.h"
#include "CoordinatesComponent.h"

constexpr auto DEFAULT_FONT_FILE_PATH	= "Source/Fonts/OpenSans-Regular.ttf";
constexpr auto DEFAULT_FONT_SIZE		= 60;

struct FontComponent
{
	FontComponent();
	FontComponent(int fontSize, std::string fontFilePath);
	~FontComponent();

	FontComponent(const FontComponent&) = delete;
	void operator=(const FontComponent&) = delete;

	void DrawText(std::string text, CoordinatesComponent coordinates, SDL_Color fontColor = { 0, 0, 0, 0 });
	
	TTF_Font* font;
};
