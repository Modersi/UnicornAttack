#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact)
{
//**  Get two colliding objects name  **//
	std::string FirstCollidingObjectName = reinterpret_cast<char*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	std::string SecondCollidingObjectName = reinterpret_cast<char*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

//**  Check if Unicorn collide with any star  **//
	if (contact->IsTouching())
		if (FirstCollidingObjectName == "Unicorn" && SecondCollidingObjectName == "Star"
			||
			FirstCollidingObjectName == "Star" && SecondCollidingObjectName == "Unicorn")
			unicornTouchingStar = true;

//**  Check if Unicorn collide with any ground spikes  **//
	if (contact->IsTouching())
		if (FirstCollidingObjectName == "Unicorn" && SecondCollidingObjectName == "GroundSpikes"
			||
			FirstCollidingObjectName == "GroundSpikes" && SecondCollidingObjectName == "Unicorn")
			unicornTouchingGroundSpikes = true;

//**  Check if Unicorn collide with any ground  **//
	if (contact->IsTouching())
		if (FirstCollidingObjectName == "Unicorn" && SecondCollidingObjectName == "Ground"
			||
			FirstCollidingObjectName == "Ground" && SecondCollidingObjectName == "Unicorn")
			unicornTouchingGround = true;
}

void ContactListener::EndContact(b2Contact* contact)
{
//**  Get two colliding objects name  **//
	std::string FirstCollidingObjectName = reinterpret_cast<char*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	std::string SecondCollidingObjectName = reinterpret_cast<char*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

//**  Check if Unicorn collide with any star  **//
	if (FirstCollidingObjectName == "Unicorn" && SecondCollidingObjectName == "Star"
		||
		FirstCollidingObjectName == "Star" && SecondCollidingObjectName == "Unicorn")
		unicornTouchingStar = false;

//**  Check if Unicorn ended contact with any ground spikes  **//
	if (FirstCollidingObjectName == "Unicorn" && SecondCollidingObjectName == "GroundSpikes"
		||
		FirstCollidingObjectName == "GroundSpikes" && SecondCollidingObjectName == "Unicorn")
		unicornTouchingGroundSpikes = false;

//**  Check if Unicorn ended contact with any ground  **//
	if (FirstCollidingObjectName == "Unicorn" && SecondCollidingObjectName == "Ground"
		||
		FirstCollidingObjectName == "Ground" && SecondCollidingObjectName == "Unicorn")
		unicornTouchingGround = false;
}
