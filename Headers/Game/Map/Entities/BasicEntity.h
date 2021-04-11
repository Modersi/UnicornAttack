#pragma once

#include "Game.h"
#include "Camera.h"
#include "Components/CoordinatesComponent.h"
#include "Components/TextureComponent.h"


class BasicEntity 
{
public:
	BasicEntity();
	BasicEntity(int entityXPosition, int entityYPosition,
		        std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight);

	void DestroyEntity();

	int getTextureWidth() const;
	int getTextureHeight() const;

	virtual void Update() = 0;

	virtual void Render() const = 0;

	virtual void Restart() = 0;

	virtual int GetXPosition() const = 0;	
	virtual int GetYPosition() const = 0;

	virtual void SetPosition(const int& xPosition, const int& yPosition) = 0;
	virtual void SetPosition(const SDL_Rect& positionRectangle) = 0;
	virtual void SetPosition(const b2Vec2& positionCoordinates) = 0;
	virtual void SetPosition(const CoordinatesComponent& positionCoordinates) = 0;

protected:
	CoordinatesComponent entityCoordinates;
	TextureComponent entityTexture;
	b2Body* entityCollisionBody;
};