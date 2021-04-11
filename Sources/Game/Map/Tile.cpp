#include "Map/Tile.h"
#include "Map/Map.h"

Tile::Tile(int tileXPosition, int tileYPostion) : 
	tileCoordinates(tileXPosition, tileYPostion),
	tileGround(),
	tileStars(),
	tileGroundSpikes()
{}

void Tile::DestroyTile()
{
	for (auto&& star : tileStars)
		star.DestroyEntity();

	for (auto&& spikes : tileGroundSpikes)
		spikes.DestroyEntity();

	tileGround.DestroyEntity();
}

void Tile::Update()
{
	for (auto&& star : tileStars)
		star.Update();

	for (auto&& spikes : tileGroundSpikes)
		spikes.Update();

	tileGround.Update();
}

void Tile::Render() const
{
	for (auto&& star : tileStars)
		star.Render();

	tileGround.Render();

	for (auto&& spikes : tileGroundSpikes)
		spikes.Render();
}

void Tile::Restart()
{
	for (auto&& star : tileStars)
		star.Restart();

	for (auto&& spikes : tileGroundSpikes)
		spikes.Restart();

	tileGround.Restart();

	tileCoordinates.Restart();
}

void Tile::AddStar(int relativeStarXPosition, int relativeStarYPosition)
{
//**  Creating a star and adding it to entity list of this tile  **//
	tileStars.push_back(SquareStaticEntity(tileCoordinates.xPosition + relativeStarXPosition, tileCoordinates.yPosition + relativeStarYPosition, STAR_TEXTURE_PATH, STAR_TEXTURE_WIDTH, STAR_TEXTURE_HEIGHT, "Star"));
}

void Tile::AddGroundSpikes(int relativeSpikesXPosition, int relativeSpikesYPosition)
{
//**  Creating a ground spikes and adding them to entity list of this tile  **//
	tileGroundSpikes.push_back(SquareStaticEntity(tileCoordinates.xPosition + relativeSpikesXPosition, tileCoordinates.yPosition + relativeSpikesYPosition, GROUND_SPIKES_TEXTURE_PATH, GROUND_SPIKES_TEXTURE_WIDTH, GROUND_SPIKES_TEXTURE_HEIGHT, "GroundSpikes"));
}

void Tile::SetGround(int relativeGroundXPosition, int relativeGroundYPosition, std::string groundTexturePath, int groundTextureWidth, int groundTextureHeight, std::vector<b2Vec2> groundVertexes)
{
//**  Assing new ground to tile  **//
	tileGround = MultiVertexStaticEntity(tileCoordinates.xPosition + relativeGroundXPosition, tileCoordinates.yPosition + relativeGroundYPosition, groundTexturePath, groundTextureWidth, groundTextureHeight, groundVertexes, "Ground");
}

int Tile::getTileWidth() const
{
	return ((tileGround.GetXPosition() - tileCoordinates.xPosition) + tileGround.getTextureWidth());
}

int Tile::getTileHeight() const
{
	return tileGround.getTextureHeight();
}

int Tile::GetXPosition() const
{
	return tileCoordinates.xPosition;
}

int Tile::GetYPosition() const
{
	return tileCoordinates.yPosition;
}

void Tile::SetPosition(const int& xPosition, const int& yPosition)
{
//**  Changing all tile entities position. '*entity*.Get*Position() - tileCoordinates.Position' it's entity coordinates relative to tile coordinates)  **//

	/* Changing all tile stars position */
	for (auto&& star : tileStars)
		star.SetPosition(xPosition + (star.GetXPosition() - tileCoordinates.xPosition),
						 yPosition + (star.GetYPosition() - tileCoordinates.yPosition));

	/* Changing all tile ground spikes position */
	for (auto&& spikes : tileGroundSpikes)
		spikes.SetPosition(xPosition + (spikes.GetXPosition() - tileCoordinates.xPosition),
						   yPosition + (spikes.GetYPosition() - tileCoordinates.yPosition));

	/*  Changing ground position  */
	tileGround.SetPosition(xPosition + (tileGround.GetXPosition() - tileCoordinates.xPosition),
						   yPosition + (tileGround.GetYPosition() - tileCoordinates.yPosition));

	/*  Changing tile position  */
	tileCoordinates.xPosition = xPosition;
	tileCoordinates.yPosition = yPosition;
}

void Tile::SetPosition(const SDL_Rect& positionRectangle)
{
	for (auto&& star : tileStars)
		star.SetPosition(positionRectangle.x + (star.GetXPosition() - tileCoordinates.xPosition),
						 positionRectangle.y + (star.GetYPosition() - tileCoordinates.yPosition));

	for (auto&& spikes : tileGroundSpikes)
		spikes.SetPosition(positionRectangle.x + (spikes.GetXPosition() - tileCoordinates.xPosition),
			               positionRectangle.y + (spikes.GetYPosition() - tileCoordinates.yPosition));

	tileGround.SetPosition(positionRectangle.x + (tileGround.GetXPosition() - tileCoordinates.xPosition),
						   positionRectangle.y + (tileGround.GetYPosition() - tileCoordinates.yPosition));

	tileCoordinates.xPosition = positionRectangle.x;
	tileCoordinates.yPosition = positionRectangle.y;
}

void Tile::SetPosition(const b2Vec2& positionCoordinates)
{
	for (auto&& star : tileStars)
		star.SetPosition(METERS_TO_PIXELS(positionCoordinates.x) + (star.GetXPosition() - tileCoordinates.xPosition),
						 -METERS_TO_PIXELS(positionCoordinates.y) + (star.GetYPosition() - tileCoordinates.yPosition));

	for (auto&& spikes : tileGroundSpikes)
		spikes.SetPosition(positionCoordinates.x + (spikes.GetXPosition() - tileCoordinates.xPosition),
						   positionCoordinates.y + (spikes.GetYPosition() - tileCoordinates.yPosition));

	tileGround.SetPosition(METERS_TO_PIXELS(positionCoordinates.x) + (tileGround.GetXPosition() - tileCoordinates.xPosition),
						   -METERS_TO_PIXELS(positionCoordinates.y) + (tileGround.GetYPosition() - tileCoordinates.yPosition));

	tileCoordinates.xPosition = METERS_TO_PIXELS(positionCoordinates.x);
	tileCoordinates.yPosition = -METERS_TO_PIXELS(positionCoordinates.y);
}


void Tile::SetPosition(const CoordinatesComponent& positionCoordinates)
{
	for (auto&& star : tileStars)
		star.SetPosition(positionCoordinates.xPosition + (star.GetXPosition() - tileCoordinates.xPosition),
						 positionCoordinates.yPosition + (star.GetYPosition() - tileCoordinates.yPosition));

	for (auto&& spikes : tileGroundSpikes)
		spikes.SetPosition(positionCoordinates.xPosition + (spikes.GetXPosition() - tileCoordinates.xPosition),
						   positionCoordinates.yPosition + (spikes.GetYPosition() - tileCoordinates.yPosition));

	tileGround.SetPosition(positionCoordinates.xPosition + (tileGround.GetXPosition() - tileCoordinates.xPosition),
						   positionCoordinates.yPosition + (tileGround.GetYPosition() - tileCoordinates.yPosition));

	tileCoordinates = positionCoordinates;
}


