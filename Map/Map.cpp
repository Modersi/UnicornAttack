#include "Map.h"
#include <stdlib.h>
#include <ctime> 



Map::Map() : 
//**  Initializing background texture **//
	backgroundTexture(BACKGROUND_TEXTURE_PATH, BACKGROUND_TEXTURE_WIDTH, BACKGROUND_TEXTURE_HEIGHT)
{
//** Initializing seed of random generator  **//
	std::random_device randomNumber;
	randomNumbersGenerator.seed(randomNumber());

//**  Creating tiles   **//

	std::vector<b2Vec2> groundVertexes;

	/* First tile */
	tiles.push_back(Tile(0, 400));


	groundVertexes = { {0.0f, -PIXELS_TO_METERS(237)},
					   {PIXELS_TO_METERS(612), -PIXELS_TO_METERS(237)},
					   {PIXELS_TO_METERS(612), 0.0f},
					   {PIXELS_TO_METERS(1225), 0.0f},
					   {PIXELS_TO_METERS(1225), -PIXELS_TO_METERS(639)},
					   {0.0f, -PIXELS_TO_METERS(639)} };

	tiles[0].SetGround(0, 0, GROUND_1_TEXTURE_PATH, GROUND_1_TEXTURE_WIDTH, GROUND_1_TEXTURE_HEIGHT, groundVertexes);
	tiles[0].AddStar(750, -180);
	tiles[0].AddGroundSpikes(560, 50);

	/* Second tile */
	tiles.push_back(Tile(2000, 700));

	groundVertexes = { {0.0f, 0.0f},
					   {PIXELS_TO_METERS(611), 0.0f},
					   {PIXELS_TO_METERS(611), -PIXELS_TO_METERS(237)},
					   {PIXELS_TO_METERS(1224), -PIXELS_TO_METERS(237)},
					   {PIXELS_TO_METERS(1224), 0.0f},
					   {PIXELS_TO_METERS(1834), 0.0f},
					   {PIXELS_TO_METERS(1834), -PIXELS_TO_METERS(639)},
					   {0.0f, -PIXELS_TO_METERS(639)} };

	tiles[1].SetGround(0, 0, GROUND_2_TEXTURE_PATH, GROUND_2_TEXTURE_WIDTH, GROUND_2_TEXTURE_HEIGHT, groundVertexes);
	tiles[1].AddStar(400, -180);
	tiles[1].AddGroundSpikes(1185, 50);
}

Map::~Map()
{
//** All tiles de$$troying **//
	for (auto&& tile : tiles)
		tile.DestroyTile();
}

void Map::Update()
{
//** All tiles update **//
	for (auto&& tile : tiles)
		tile.Update();

//**  Initialization of distribution generators **//

	std::uniform_int_distribution<int> randomDistanceBetweenTiles(500, 1500); // (min distance, max distance)
	std::uniform_int_distribution<int> randomTileYPosition(0 , 500); // (min y delta, max y delta)

//** Manipulations with tiles to create an endless map **//

	/* Check if the most left (tiles[0] is always most left) tile is out of screen on left side */
	if (tiles[1].GetXPosition() < Game::camera->GetXPosition())
	{
		//std::cout << "---------Before---------" << std::endl;
		//for (size_t i = 0; i < tiles.size(); i++)
		//	std::cout << "ID[" << i << "] X: " << tiles[i].GetXPosition() << " Y : " << tiles[i].GetYPosition() << std::endl;
	
		/* Put most left(always tiles[0]) tile coordinates to the end of all tiles on right side */
		tiles[0].SetPosition(tiles[tiles.size() - 1].GetXPosition() + tiles[tiles.size() - 1].getTileWidth() + randomDistanceBetweenTiles(randomNumbersGenerator),
							 tiles[0].GetYPosition() + randomTileYPosition(randomNumbersGenerator));
	
		/* And put this tile to end of tiles vector simply by adding him to end and deleting him from begin */
		tiles.push_back(tiles[0]);
		tiles.erase(tiles.begin());
	
		//std::cout << "---------After---------" << std::endl;
		//for (size_t i = 0; i < tiles.size(); i++)
		//	std::cout << "ID[" << i << "] X: " << tiles[i].GetXPosition() << " Y : " << tiles[i].GetYPosition() << std::endl;
	}
}

void Map::Render() const
{
//** Background texture render **//
	SDL_RenderCopy(Game::renderer, backgroundTexture.texture, NULL, NULL);

//** All tiles render **//
	for (auto&& tile : tiles)
		tile.Render();
}

void Map::Restart()
{
//** All tiles restart **//
	for (auto&& tile : tiles)
		tile.Restart();
}