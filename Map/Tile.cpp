#include "Tile.h"

Tile::Tile(CoordinatesComponent tileCoordinates, TextureComponent groundTexture) : coordinates(tileCoordinates)
{
	ground = MapEntity(tileCoordinates, groundTexture);
	entities = std::vector<MapEntity>();
}

void Tile::Update()
{
	ground.coordinates.xPosition = coordinates.xPosition;

	for (auto&& entity : entities)
		entity.coordinates.xPosition = coordinates.xPosition + entity.coordinates.xPosition;

	/*for (int i = 0; i < blocksCount; i++)
		blocks[i].destinationRectangle.x = xPosition + blocks[i].xPosition;*/
}

void Tile::Render()
{
	ground.Render();
	for (auto&& entity : entities)
		entity.Render();
}

void Tile::addEntity(CoordinatesComponent entityCoordinates, TextureComponent entityTexture)
{
	entities.push_back(MapEntity(entityCoordinates, entityTexture));
}
