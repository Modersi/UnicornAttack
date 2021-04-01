#pragma once

#include "../Game/Game.h"
#include "Entities/MultiVertexStaticEntity.h"
#include "Entities/SquareStaticEntity.h"

class Tile
{
public:
	Tile(int tileXPosition, int tileYPosition);
	void DestroyTile();

	void Update();

	void Render() const;

	void Restart();

	void AddStar(int relativeStarXPosition, int relativeStarYPosition);

	void AddGroundSpikes(int relativeSpikesXPosition, int relativeSpikesYPosition);

	void SetGround(int relativeGroundXPosition, int relativeGroundYPosition,
				   std::string groundTexturePath, int groundTextureWidth, int groundTextureHeight,
				   std::vector<b2Vec2> groundVertexes);

	int getTileWidth() const;
	int getTileHeight() const;

	int GetXPosition() const;
	int GetYPosition() const;

	void SetPosition(const int& xPosition, const int& yPosition);
	void SetPosition(const SDL_Rect& positionRectangle);
	void SetPosition(const b2Vec2& positionCoordinates);
	void SetPosition(const CoordinatesComponent& positionCoordinates);

private:
	MultiVertexStaticEntity tileGround;
	std::vector<SquareStaticEntity> tileStars;
	std::vector<SquareStaticEntity> tileGroundSpikes;
	CoordinatesComponent tileCoordinates;
};
