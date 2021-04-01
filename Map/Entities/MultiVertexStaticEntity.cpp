#include "MultiVertexStaticEntity.h"

MultiVertexStaticEntity::MultiVertexStaticEntity() :
	BasicEntity()
{}

MultiVertexStaticEntity::MultiVertexStaticEntity(int entityXPosition, int entityYPosition, std::string entityTexturePath, int entityTextureWidth, int entityTextureHeight, std::vector<b2Vec2> entityVertexes, const char* entityName) :
	BasicEntity(entityXPosition, entityYPosition, entityTexturePath, entityTextureWidth, entityTextureHeight)
{
//**  Setting up Box2D entity data to make a ground  **//

	/* Setting up entity body type and position */
	b2BodyDef bodyDefinition;
	bodyDefinition.type = b2_staticBody;
	bodyDefinition.position.Set(PIXELS_TO_METERS(entityXPosition), -PIXELS_TO_METERS(entityYPosition));
	bodyDefinition.userData.pointer = reinterpret_cast<uintptr_t>(entityName);

	/* Adding entity to Box2D world */
	entityCollisionBody = Game::box2DWorld->CreateBody(&bodyDefinition);

	/* Adding entity shapes to body */
	b2EdgeShape groundShape;
	for (size_t i = 0; i < entityVertexes.size() - 1; i++)
	{
		if (i == 0)
		{
			groundShape.SetTwoSided(entityVertexes[i], entityVertexes[entityVertexes.size() - 1]);
			entityCollisionBody->CreateFixture(&groundShape, 0.0f);
		}
		groundShape.SetTwoSided(entityVertexes[i], entityVertexes[i + 1]);
		entityCollisionBody->CreateFixture(&groundShape, 0.0f);
	}
}

void MultiVertexStaticEntity::Update()
{
	entityCoordinates.xPosition = METERS_TO_PIXELS(entityCollisionBody->GetPosition().x);
	entityCoordinates.yPosition = -METERS_TO_PIXELS(entityCollisionBody->GetPosition().y);
}

void MultiVertexStaticEntity::Render() const
{
	SDL_Rect destinationRectangle = {	entityCoordinates.xPosition - Game::camera->GetXPosition(),
										entityCoordinates.yPosition - Game::camera->GetYPosition(),
										entityTexture.textureWidth,
										entityTexture.textureHeight };

	SDL_RenderCopy(Game::renderer, entityTexture.texture, NULL, &destinationRectangle);
}

void MultiVertexStaticEntity::Restart()
{
	/* Setting entity coordinates back to start */
	entityCoordinates.Restart();

	/* Setting collision body coordinates back to start */
	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(entityCoordinates.xPosition),
											-PIXELS_TO_METERS(entityCoordinates.yPosition)), 0.0f);
}

int MultiVertexStaticEntity::GetXPosition() const
{
	return entityCoordinates.xPosition;
}

int MultiVertexStaticEntity::GetYPosition() const
{
	return entityCoordinates.yPosition;
}

void MultiVertexStaticEntity::SetPosition(const int& xPosition, const int& yPosition)
{
	entityCoordinates.xPosition = xPosition;
	entityCoordinates.yPosition = yPosition;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(xPosition), -PIXELS_TO_METERS(yPosition)), 0.0f);
}

void MultiVertexStaticEntity::SetPosition(const SDL_Rect& positionRectangle)
{
	entityCoordinates.xPosition = positionRectangle.x;
	entityCoordinates.yPosition = positionRectangle.y;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(positionRectangle.x), -PIXELS_TO_METERS(positionRectangle.y)), 0.0f);
}

void MultiVertexStaticEntity::SetPosition(const b2Vec2& positionCoordinates)
{
	entityCoordinates.xPosition = positionCoordinates.x;
	entityCoordinates.yPosition = positionCoordinates.y;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(positionCoordinates.x), -PIXELS_TO_METERS(positionCoordinates.y)), 0.0f);
}

void MultiVertexStaticEntity::SetPosition(const CoordinatesComponent& positionCoordinates)
{
	entityCoordinates = positionCoordinates;

	entityCollisionBody->SetTransform(b2Vec2(PIXELS_TO_METERS(positionCoordinates.xPosition), -PIXELS_TO_METERS(positionCoordinates.yPosition)), 0.0f);
}
