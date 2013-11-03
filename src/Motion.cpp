#include "Motion.h"
#include <math.h>

Motion::Motion() :
	gravity(0.0f), friction(0.0f), maxSpeed(0.0f), maxZSpeed(0.0f)
{
	velocity *= 0.0f;
	zVelocity = 0.0f;
}

Motion::Motion(float gravity, float friction, float maxSpeed, float maxZSpeed) :
	gravity(gravity), friction(friction), maxSpeed(maxSpeed), maxZSpeed(maxZSpeed)
{
	velocity *= 0.0f;
	zVelocity = 0.0f;
}

void Motion::applyGravity()
{
	zVelocity -= gravity;
}

void Motion::applyFriction()
{
	if (friction > 0.0f)
	{
		velocity.x /= friction;
		velocity.y /= friction;
	}
}

//Do you has optimize?
void Motion::applyMaxSpeed()
{
	// 2D plane speed
	float x2	= velocity.x*velocity.x;
	float y2	= velocity.y*velocity.y;
	float max2	= maxSpeed*maxSpeed;

	if (x2 + y2 > max2 && max2 > 0.0f)
	{
		float speedLimiter = sqrt((x2 + y2)/max2);
		velocity.x /= speedLimiter;
		velocity.y /= speedLimiter;
	}

	// z speed
	if (zVelocity > maxZSpeed)
		zVelocity = maxZSpeed;
	if (zVelocity < -maxZSpeed)
		zVelocity = -maxZSpeed;
}