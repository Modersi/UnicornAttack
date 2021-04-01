#include "BasicEntity.h"

BasicEntity::BasicEntity() :
	entityCoordinates(),
	entityTexture(),
	entityCollisionBody()
{}

BasicEntity::BasicEntity(int entityXPosition, int entityYPosition, std::string texturePath, int textureWidth, int textureHeight) :
//**  Setting up entity coordinates **/ /
	entityCoordinates(entityXPosition, entityYPosition),

//**  Creating entity texture **//
	entityTexture(texturePath, textureWidth, textureHeight),

//**  Creating entity collision body **//
	entityCollisionBody()
{}

void BasicEntity::DestroyEntity()
{
	this->~BasicEntity();
	entityTexture.DestroyTexture();
}

int BasicEntity::getTextureWidth() const
{
	return entityTexture.textureWidth;
}

int BasicEntity::getTextureHeight() const
{
	return entityTexture.textureHeight;
}
