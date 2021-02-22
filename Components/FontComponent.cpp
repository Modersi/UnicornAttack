#include "FontComponent.h"

FontComponent::FontComponent()
{
	font = TTF_OpenFont(DEFAULT_FONT_FILE_PATH, DEFAULT_FONT_SIZE);
	if (!font)
		std::cout << "FontComponent default constructor error:  " << TTF_GetError() << std::endl; // Добавить свой класс Exepcion-ов и бросить exeption
}

FontComponent::FontComponent(int fontSize, std::string fontFilePath)
{
	font = TTF_OpenFont(fontFilePath.c_str(), fontSize);
	if (!font)
		std::cout << "FontComponent constructor error:  " << TTF_GetError() << std::endl; // Добавить свой класс Exepcion-ов и бросить exeption
}

FontComponent::~FontComponent()
{
	TTF_CloseFont(font);
}

void FontComponent::DrawText(std::string text, CoordinatesComponent coordinates, SDL_Color fontColor)
{	
	/* Render text on surface and create a texture from this surface */
	SDL_Surface* tempSurface = TTF_RenderText_Blended(font, text.c_str(), fontColor);
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

	/* Set all fields of text render rectangle */
	/* TTF_RenderText_Blended rendering text on surface with empty space in size of DEFAULT_FONT_SIZE / 4 in top part of surface, so we just minus it to render text in right place */
	SDL_Rect textRenderDestinationRectangle = {coordinates.xPosition , coordinates.yPosition - DEFAULT_FONT_SIZE / 4 , 0 , 0};
	TTF_SizeText(font, text.c_str(), &textRenderDestinationRectangle.w, &textRenderDestinationRectangle.h);

	/* Render text */
	SDL_RenderCopy(Game::renderer, tempTexture, NULL, &textRenderDestinationRectangle);

	/* Delete temp variables */
	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(tempTexture);
}


