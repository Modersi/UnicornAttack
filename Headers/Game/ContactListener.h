#pragma once

#include "Game.h"

class ContactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact) override;

	void EndContact(b2Contact* contact) override;

	bool unicornTouchingGround = false;
	bool unicornTouchingStar = false;
	bool unicornTouchingGroundSpikes = false;
};
