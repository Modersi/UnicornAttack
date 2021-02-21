#pragma once

#include "Game.h"
#include "MapEntity.h"

struct Tile
{
	Tile(CoordinatesComponent tileCoordinates, TextureComponent groundTexture);

	void Update();

	void Render();

	void addEntity(CoordinatesComponent entityCoordinates, TextureComponent entityTexture);


	MapEntity ground;
	std::vector<MapEntity> entities;
	CoordinatesComponent coordinates;
};
