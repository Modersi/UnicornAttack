#pragma once

#include "../Game/Game.h"
#include "MapEntity.h"

struct Tile
{
	Tile(int tileXPosition, int tileYPostion, std::string groundTexturePath, int groundTextureWidth, int groundTextureHeight);


	void Update();

	void Render();

	void addEntity(int entityXPosition, int entityYPostion, std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight);


	MapEntity ground;
	std::vector<MapEntity> entities;
	CoordinatesComponent coordinates;
};
