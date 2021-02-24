#pragma once

#include "../Game/Game.h"
#include "../Components/CoordinatesComponent.h"
#include "../Components/TextureComponent.h"

struct MapEntity 
{
	MapEntity();
	MapEntity(int entityXPositon, int entityYPostion, std::string texturePath, int textureWidth, int textureHeight);


	void Render();

	CoordinatesComponent coordinates;
	TextureComponent texture;
};