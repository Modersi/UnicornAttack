#include "Components/FontComponent.h"

FontComponent::FontComponent()
{
	font = TTF_OpenFont(DEFAULT_FONT_FILE_PATH, DEFAULT_FONT_SIZE);
	if (!font)
		std::cout << "FontComponent default constructor error:  " << TTF_GetError() << std::endl;
}

FontComponent::FontComponent(int fontSize, std::string fontFilePath)
{
	font = TTF_OpenFont(fontFilePath.c_str(), fontSize);
	if (!font)
		std::cout << "FontComponent constructor error:  " << TTF_GetError() << std::endl;
}

void FontComponent::DestroyFont()
{
	TTF_CloseFont(font);
}

void FontComponent::DrawText(std::string text, int xPositon, int yPosition, SDL_Color fontColor)
{	
	/* Rendering text on surface and create a texture from this surface */
	SDL_Surface* tempSurface = TTF_RenderText_Blended(font, text.c_str(), fontColor);
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

	/* TTF_RenderText_Blended render text on surface with empty space in top part of surface, so we just minus it to render text in right place */
	SDL_Rect textRenderDestinationRectangle = { xPositon , yPosition - DEFAULT_FONT_SIZE / 4 , 0 , 0};
	TTF_SizeText(font, text.c_str(), &textRenderDestinationRectangle.w, &textRenderDestinationRectangle.h);

	/* Rendering text on screen */
	SDL_RenderCopy(Game::renderer, tempTexture, NULL, &textRenderDestinationRectangle);

	/* Deleting temporary variables */
	SDL_FreeSurface(tempSurface);
	SDL_DestroyTexture(tempTexture);
}


