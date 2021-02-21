#include "FontComponent.h"

FontComponent::FontComponent() 
{
	font = TTF_OpenFont(DEFAULT_FONT_FILE_PATH, DEFAULT_FONT_SIZE);
	if (font == NULL)
		std::cout << "FontComponent default constructor error:  " << TTF_GetError() << std::endl; // Добавить свой класс Exepcion-ов и бросить exeption
}

FontComponent::FontComponent(int fontSize, std::string fontFilePath)
{
	font = TTF_OpenFont(fontFilePath.c_str, fontSize);
	if (font == NULL)
		std::cout << "FontComponent constructor error:  " << TTF_GetError() << std::endl; // Добавить свой класс Exepcion-ов и бросить exeption
}

FontComponent::~FontComponent()
{
	TTF_CloseFont(font);
}

void FontComponent::DrawText(std::string text, CoordinatesComponent coordinates, SDL_Color fontColor)
{	
	int textRenderWidth, textRenderHeight;
	
	if (TTF_SizeText(font, text.c_str, &textRenderWidth, &textRenderHeight) != 0)
		std::cout << "DrawText error: " << TTF_GetError() << std::endl; // Добавить свой класс Exepcion-ов и бросить exeption
	else
	{
		SDL_Surface* tempSurface = TTF_RenderText_Solid(font, text.c_str(), fontColor);
		SDL_Rect textRenderDestinationRectangle = { coordinates.xPosition, coordinates.yPosition, textRenderWidth, textRenderHeight };

		SDL_RenderCopy(Game::renderer, SDL_CreateTextureFromSurface(Game::renderer, tempSurface), NULL, &textRenderDestinationRectangle);

		SDL_FreeSurface(tempSurface);
	}
	
}


