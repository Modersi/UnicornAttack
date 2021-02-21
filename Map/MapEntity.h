#pragma once

#include "Game.h"
#include "CoordinatesComponent.h"
#include "TextureComponent.h"

struct MapEntity 
{
	MapEntity();
	MapEntity(CoordinatesComponent entityCoordinates, TextureComponent entityTexture);

	void Render();

	CoordinatesComponent coordinates;
	TextureComponent texture;
};