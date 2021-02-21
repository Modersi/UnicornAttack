#pragma once

#include "../Game/Game.h"
#include "../Components/CoordinatesComponent.h"
#include "../Components/TextureComponent.h"

struct MapEntity 
{
	MapEntity();
	MapEntity(CoordinatesComponent entityCoordinates, TextureComponent entityTexture);

	void Render();

	CoordinatesComponent coordinates;
	TextureComponent texture;
};