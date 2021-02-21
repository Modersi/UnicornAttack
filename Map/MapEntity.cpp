#include "MapEntity.h"

MapEntity::MapEntity() : coordinates(CoordinatesComponent()), texture(TextureComponent()) {}

MapEntity::MapEntity(CoordinatesComponent entityCoordinates, TextureComponent entityTexture) 
	: coordinates(entityCoordinates), texture(entityTexture) {}

void MapEntity::Render()
{
	SDL_Rect destinationRectangle = { coordinates.xPosition, coordinates.yPosition, texture.textureWidth, texture.textureHeight };
	SDL_RenderCopy(Game::renderer, texture.texture, NULL, &destinationRectangle);
}