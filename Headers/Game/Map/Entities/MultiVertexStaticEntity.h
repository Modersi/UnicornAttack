#pragma once

#include "Game.h"
#include "Components/CoordinatesComponent.h"
#include "Components/TextureComponent.h"
#include "Map/Entities/BasicEntity.h"

class MultiVertexStaticEntity : public BasicEntity
{
public:
	MultiVertexStaticEntity();
	MultiVertexStaticEntity(int entityXPosition, int c,
		                    std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight,
		                    std::vector<b2Vec2> entityVertexes, const char* entityName);

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
