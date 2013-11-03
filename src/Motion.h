#ifndef _MOTION_H
#define _MOTION_H

#include <SFML\Graphics.hpp>

class Motion
{
public:
	Motion();
	Motion(float gravity, float friction, float maxSpeed, float maxZSpeed);
	virtual ~Motion() {}

	void applyGravity();
	void applyFriction();
	void applyMaxSpeed();
	
	float gravity;
	float friction;
	float maxSpeed;
	float maxZSpeed;
	sf::Vector2f velocity;
	float zVelocity;
};
#endif // _MOTION_H