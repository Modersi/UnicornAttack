#include "Tile.h"

Tile::Tile(int tileXPosition, int tileYPostion, std::string groundTexturePath, int groundTextureWidth, int groundTextureHeight) : 
	coordinates	(tileXPosition, tileYPostion),
	ground		(tileXPosition, tileYPostion, groundTexturePath, groundTextureWidth, groundTextureHeight),
	entities	() 
{}

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

void Tile::addEntity(int entityXPosition, int entityYPostion, std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight)
{
	//entities.push_back({ entityXPosition, entityYPostion, entityTexturePath, entityTextureWidth, entityTextureHeight });
}
