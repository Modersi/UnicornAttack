#include "Map.h"
#include <stdlib.h>
#include <ctime> 



Map::Map()
{
	tiles.push_back(Tile(0, GROUND_Y, GROUND_TEXTURE_PATH, GROUND_TEXTURE_WIDTH, GROUND_TEXTURE_HEIGHT));
	tiles.push_back(Tile(GROUND_TEXTURE_WIDTH, GROUND_Y - 100, GROUND_TEXTURE_PATH, GROUND_TEXTURE_WIDTH, GROUND_TEXTURE_HEIGHT));
	tiles.push_back(Tile(GROUND_TEXTURE_WIDTH * 2, GROUND_Y - 200, GROUND_TEXTURE_PATH, GROUND_TEXTURE_WIDTH, GROUND_TEXTURE_HEIGHT));

	//tiles[1].addEntity(1300, tiles[1].ground.coordinates.yPosition - BLOCK_TEXTURE_HEIGHT, BLOCK_TEXTURE_PATH, BLOCK_TEXTURE_WIDTH, BLOCK_TEXTURE_HEIGHT);
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

	/* Manipulations with tiles to create a endless map */
	/* Check if the most left (tiles[0] is always most left) tile is out of screen on left side */
	if (tiles[0].coordinates.xPosition + tiles[0].ground.texture.textureWidth < 0)
	{
		//std::cout << "---------Before---------" << std::endl;
		//for (size_t i = 0; i < tiles.size(); i++)
		//	std::cout << "ID[" << i << "] X: " << tiles[i].coordinates.xPosition << " Y : " << tiles[i].coordinates.yPosition << std::endl;

		/* Put this tile coordinates to the end of all tiles on right side */
		tiles[0].coordinates.xPosition = tiles[tiles.size() - 1].coordinates.xPosition + tiles[tiles.size() - 1].ground.texture.textureWidth;
		/* And put this tile to end of tiles[] by adding him to end and deleting him from begin */
		tiles.push_back(tiles[0]);
		tiles.erase(tiles.begin());

		//std::cout << "---------After---------" << std::endl;
		//for (size_t i = 0; i < tiles.size(); i++)
		//	std::cout << "ID[" << i << "] X: " << tiles[i].coordinates.xPosition << " Y : " << tiles[i].coordinates.yPosition << std::endl;
	}
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
