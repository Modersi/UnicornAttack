#pragma once

#include "Game.h"
#include "CoordinatesComponent.h"

constexpr auto DEFAULT_FONT_FILE_PATH = "./PixelFont.ttf";
constexpr auto DEFAULT_FONT_SIZE = 32;

struct FontComponent
{
	FontComponent();
	FontComponent(int fontSize, std::string fontFilePath);
	~FontComponent();

	void DrawText(std::string text, CoordinatesComponent coordinates, SDL_Color fontColor = { 0, 0, 0, 0 });
	
	TTF_Font* font;
};
