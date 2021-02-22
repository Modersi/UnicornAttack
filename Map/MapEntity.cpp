#include "MapEntity.h"

MapEntity::MapEntity() : coordinates(), texture() {}

MapEntity::MapEntity(int entityXPositon, int entityYPostion, std::string texturePath, int textureWidth, int textureHeight) : 
	coordinates	(entityXPositon, entityYPostion),
	texture		(texturePath, textureWidth, textureHeight) {}

void MapEntity::Render()
{
	SDL_Rect destinationRectangle = { coordinates.xPosition, coordinates.yPosition, texture.textureWidth, texture.textureHeight };
	SDL_RenderCopy(Game::renderer, texture.texture, NULL, &destinationRectangle);
}