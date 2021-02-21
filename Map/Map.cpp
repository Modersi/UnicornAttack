#include "Map.h"
#include <stdlib.h>
#include <ctime> 



Map::Map()
{
	// Creating 2 Tiles to build a map
	tiles.push_back(Tile({ 0, GROUND_Y }, { GROUND_TEXTURE_PATH, GROUND_TEXTURE_WIDTH, GROUND_TEXTURE_HEIGHT }));
	tiles.push_back(Tile({ GROUND_TEXTURE_WIDTH, GROUND_Y - 100 }, { GROUND_TEXTURE_PATH, GROUND_TEXTURE_WIDTH, GROUND_TEXTURE_HEIGHT }));

	tiles[1].addEntity({ 1300, tiles[1].ground.coordinates.yPosition - BLOCK_TEXTURE_HEIGHT }, { BLOCK_TEXTURE_PATH, BLOCK_TEXTURE_WIDTH, BLOCK_TEXTURE_HEIGHT });
}

void Map::moveMapRight(int pixelsToMove)
{
	for (auto&& tile : tiles)
		tile.coordinates.xPosition += pixelsToMove;
}

void Map::moveMapLeft(int pixelsToMove)
{
	for (auto&& tile : tiles)
		tile.coordinates.xPosition -= pixelsToMove;
}

void Map::Update()
{
	for (auto&& tile : tiles)
		tile.Update();

	/* Doings with tiles to create a endless map */
	for (auto&& tile : tiles)
	{
		/* Check if some tile is out of screen on left side */
		if (tile.coordinates.xPosition + tile.ground.texture.textureWidth < 0)
			/* Put this tile to the end of all tiles on right side */
			tile.coordinates.xPosition = tiles[tiles.size()].coordinates.xPosition + tiles[tiles.size()].ground.texture.textureWidth;
	}

	/*srand(time(NULL));
	// Check if there is end of ground on the right side
	if (tile[1]->xPosition + GROUND_TEXTURE_WIDTH < SCREEN_WIDTH)
	{
		// super-duper manipulations with tile
		tile[0]->xPosition = tile[1]->xPosition + GROUND_TEXTURE_WIDTH + (100 + rand() % 500);
		Tile *temp = tile[0];
		tile[0] = tile[1];
		tile[1] = temp;
	}

	// Check if there is end of ground on the left side
	if (tile[0]->xPosition >= 0)
	{
		// super-duper manipulations with tile
		tile[1]->xPosition = tile[0]->xPosition - GROUND_TEXTURE_WIDTH - (100 + rand() % 500);
		Tile* temp = tile[0];
		tile[0] = tile[1];
		tile[1] = temp;
	}*/
}

void Map::Render()
{
	for (auto&& tile : tiles)
		tile.Render();
}

void Map::Restart()
{
	for (auto&& tile : tiles)
		tile.coordinates.Restart();
}

/*bool Map::CheckCollizionFromRight()
{
	bool isCollide = false;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < tile[i]->blocksCount; j++)
		{
			if (Game::unicorn->getYPos() + UNICORN_TEXTURE_HEIGHT >= tile[i]->blocks[j].destinationRectangle.y)// Check if player is on block high
			{
				if (tile[i]->blocks[j].destinationRectangle.x >= Game::unicorn->getXPos()) // Check if block is from right side
				{
					if (Game::unicorn->getXPos() + UNICORN_TEXTURE_WIDTH >= tile[i]->blocks[j].destinationRectangle.x) // Check if unicorn collide with block
						isCollide = true;
				}
			}
		}	
	}
	return isCollide;
}

bool Map::CheckCollizionFromLeft()
{
	bool isCollide = false;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < tile[i]->blocksCount; j++)
		{
			if (Game::unicorn->getYPos() + UNICORN_TEXTURE_HEIGHT >= tile[i]->blocks[j].destinationRectangle.y) // Check if player higher than block
			{
				if (tile[i]->blocks[j].destinationRectangle.x <= Game::unicorn->getXPos()) // Check if block is from left side
				{
					if (Game::unicorn->getXPos() <= tile[i]->blocks[j].destinationRectangle.x + BLOCK_TEXTURE_WIDTH) // Check if unicorn collide with block
						isCollide = true;
				}
			}
		}
	}
	return isCollide;
}

bool Map::CheckCollizionFromDown()
{
	bool isCollide = false;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < tile[i]->blocksCount; j++)
		{
			if (Game::unicorn->getXPos() >= tile[i]->blocks[j].destinationRectangle.x && // Check if unicorn is staying on block
				Game::unicorn->getXPos() <= tile[i]->blocks[j].destinationRectangle.x + BLOCK_TEXTURE_WIDTH ||
				Game::unicorn->getXPos() + UNICORN_TEXTURE_WIDTH >= tile[i]->blocks[j].destinationRectangle.x &&
				Game::unicorn->getXPos() + UNICORN_TEXTURE_WIDTH <= tile[i]->blocks[j].destinationRectangle.x + BLOCK_TEXTURE_WIDTH)
			{
				if (Game::unicorn->getYPos() + UNICORN_TEXTURE_HEIGHT >= tile[i]->blocks[j].destinationRectangle.y)
					isCollide = true;
			}
		}
	}
	return isCollide;
}

bool Map::CheckCollizionWithGround()
{
	bool isCollide = false;
	for (int i = 0; i < 2; i++)
	{
		if (Game::unicorn->getXPos() >= tile[i]->ground->destinationRectangle.x &&
			Game::unicorn->getXPos() <= tile[i]->ground->destinationRectangle.x + GROUND_TEXTURE_WIDTH || 
			Game::unicorn->getXPos() + UNICORN_TEXTURE_WIDTH >= tile[i]->ground->destinationRectangle.x &&
			Game::unicorn->getXPos() + UNICORN_TEXTURE_WIDTH <= tile[i]->ground->destinationRectangle.x + GROUND_TEXTURE_WIDTH)
					if (Game::unicorn->getYPos() + UNICORN_TEXTURE_HEIGHT == tile[i]->ground->destinationRectangle.y)
						isCollide = true;

	}
	return isCollide;
}*/
