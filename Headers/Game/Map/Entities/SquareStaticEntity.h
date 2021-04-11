#pragma once

#include "Game.h"
#include "Components/CoordinatesComponent.h"
#include "Components/TextureComponent.h"
#include "Map/Entities/BasicEntity.h"

class SquareStaticEntity : public BasicEntity
{
public:
	SquareStaticEntity();
	SquareStaticEntity(int entityXPosition, int entityYPosition,
					   std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight,
					   const char* entityName);

	void Update() override;

	void Render() const override;

	void Restart() override;

	int GetXPosition() const override;
	int GetYPosition() const override;

	void SetPosition(const int& xPosition, const int& yPosition) override;
	void SetPosition(const SDL_Rect& positionRectangle) override;
	void SetPosition(const b2Vec2& positionCoordinates) override;
	void SetPosition(const CoordinatesComponent& positionCoordinates) override;
};
