
#pragma once

#include "Game.h"
#include "Unicorn.h"
#include "Tile.h"
#include "MapEntity.h"

constexpr auto GROUND_TEXTURE_PATH =	"./groundTexture.bmp";
constexpr auto GROUND_TEXTURE_HEIGHT =	75;
constexpr auto GROUND_TEXTURE_WIDTH =	3000;

constexpr auto BLOCK_TEXTURE_PATH =		"./blockTexture.bmp";
constexpr auto BLOCK_TEXTURE_HEIGHT =	180;
constexpr auto BLOCK_TEXTURE_WIDTH =	187;

struct Map
{
	Map();
	void moveMapRight(int pixelsToMove);
	void moveMapLeft(int pixelsToMove);

	void Update();

	void Render();

	void Restart();

	bool CheckCollizionFromRight();
	bool CheckCollizionFromLeft();
	bool CheckCollizionFromDown();
	bool CheckCollizionWithGround();

	std::vector<Tile> tiles;
};
