#include "SquareStaticEntity.h"

SquareStaticEntity::SquareStaticEntity() :
	BasicEntity()
{}

SquareStaticEntity::SquareStaticEntity(int entityXPosition, int entityYPosition, std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight, const char* entityName) :
	BasicEntity(entityXPosition, entityYPosition, entityTexturePath, entityTextureWidth, entityTextureHeight)
{
//**  Setting up Box2D entity data to make a square static entity and adding it to Box2D world **//

	/* Setting up the body form of entity */
	b2PolygonShape bodyShape;
	bodyShape.SetAsBox(PIXELS_TO_METERS(entityTextureWidth / 2), PIXELS_TO_METERS(entityTextureHeight / 2));

	/* Setting up fixture parameters */
	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &bodyShape;

	/* Setting up entity body type and position */
	b2BodyDef bodyDefinition;
	bodyDefinition.type = b2_staticBody;
	bodyDefinition.position.Set(PIXELS_TO_METERS(entityXPosition + (entityTextureWidth / 2)),
								-PIXELS_TO_METERS(entityYPosition + (entityTextureHeight / 2)));
	/* Why it doesn't work with std::string.c_str() !?!?!?!?!?!?!?!?!?!?!?!?!?!? */
	bodyDefinition.userData.pointer = reinterpret_cast<uintptr_t>(entityName);

	/* Adding entity to Box2D world */
	entityCollisionBody = Game::box2DWorld->CreateBody(&bodyDefinition);
	entityCollisionBody->CreateFixture(&fixtureDefinition);
}

void SquareStaticEntity::Update()
{
	entityCoordinates.xPosition = METERS_TO_PIXELS(entityCollisionBody->GetPosition().x) - (entityTexture.textureWidth / 2);
	entityCoordinates.yPosition = -METERS_TO_PIXELS(entityCollisionBody->GetPosition().y) - (entityTexture.textureHeight / 2);
}

void SquareStaticEntity::Render() const
{
	SDL_Rect destinationRectangle = {entityCoordinates.xPosition - Game::camera->GetXPosition(),
									 entityCoordinates.yPosition - Game::camera->GetYPosition(),
									 entityTexture.textureWidth,
									 entityTexture.textureHeight };

	SDL_RenderCopy(Game::renderer, entityTexture.texture, NULL, &destinationRectangle);
}

void SquareStaticEntity::Restart()
{
	/* Setting entity coordinates back to start */
	entityCoordinates.Restart();

	/* Setting collision body coordinates back to start */
	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(entityCoordinates.xPosition + (entityTexture.textureWidth / 2)),
											-PIXELS_TO_METERS(entityCoordinates.yPosition + (entityTexture.textureHeight / 2))), 0.0f);
}

int SquareStaticEntity::GetXPosition() const
{
	return entityCoordinates.xPosition;
}

int SquareStaticEntity::GetYPosition() const
{
	return entityCoordinates.yPosition;
}

void SquareStaticEntity::SetPosition(const int& xPosition, const int& yPosition)
{
	entityCoordinates.xPosition = xPosition;
	entityCoordinates.yPosition = yPosition;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(xPosition + (entityTexture.textureWidth / 2)),
											-PIXELS_TO_METERS(yPosition + (entityTexture.textureHeight / 2))), 0.0f);
}

void SquareStaticEntity::SetPosition(const SDL_Rect& positionRectangle)
{
	entityCoordinates.xPosition = positionRectangle.x;
	entityCoordinates.yPosition = positionRectangle.y;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(positionRectangle.x + (entityTexture.textureWidth / 2)),
											-PIXELS_TO_METERS(positionRectangle.y + (entityTexture.textureHeight / 2))), 0.0f);
}

void SquareStaticEntity::SetPosition(const b2Vec2& positionCoordinates)
{
	entityCoordinates.xPosition = positionCoordinates.x;
	entityCoordinates.yPosition = positionCoordinates.y;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(positionCoordinates.x + (entityTexture.textureWidth / 2)),
											-PIXELS_TO_METERS(positionCoordinates.y + (entityTexture.textureHeight / 2))), 0.0f);
}

void SquareStaticEntity::SetPosition(const CoordinatesComponent& positionCoordinates)
{
	entityCoordinates = positionCoordinates;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(positionCoordinates.xPosition + (entityTexture.textureWidth / 2)),
											-PIXELS_TO_METERS(positionCoordinates.yPosition + (entityTexture.textureHeight / 2))), 0.0f);
}
