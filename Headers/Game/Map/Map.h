#pragma once

#include "Game.h"
#include "Unicorn.h"
#include "Map/Tile.h"

constexpr auto BACKGROUND_TEXTURE_PATH =	"Textures/Background.png";
constexpr auto BACKGROUND_TEXTURE_HEIGHT =	1080;
constexpr auto BACKGROUND_TEXTURE_WIDTH =	1920;

constexpr auto GROUND_1_TEXTURE_PATH =		"Textures/Ground_1.png";
constexpr auto GROUND_1_TEXTURE_HEIGHT =	639;
constexpr auto GROUND_1_TEXTURE_WIDTH =		1225;

constexpr auto GROUND_2_TEXTURE_PATH =		"Textures/Ground_2.png";
constexpr auto GROUND_2_TEXTURE_HEIGHT =	639;
constexpr auto GROUND_2_TEXTURE_WIDTH =		1834;

constexpr auto STAR_TEXTURE_PATH =		"Textures/Star.png";
constexpr auto STAR_TEXTURE_HEIGHT =	180;
constexpr auto STAR_TEXTURE_WIDTH =		187;

constexpr auto GROUND_SPIKES_TEXTURE_PATH =		"Textures/GroundSpikes.png";
constexpr auto GROUND_SPIKES_TEXTURE_HEIGHT =	170;
constexpr auto GROUND_SPIKES_TEXTURE_WIDTH =	92;

class Map
{
public:
	Map();
	~Map();

	void Update();

	void Render() const;

	void Restart();

private:
	TextureComponent backgroundTexture;
	std::vector<Tile> tiles; // Vector which contains all tiles 
	std::mt19937 randomNumbersGenerator; // Using this generetor to make random gaps between tiles
};
