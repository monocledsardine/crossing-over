#include "Targetable.h"


void Targetable::bump(const sf::Vector2f& force, float zVel)
{
	motion.velocity += force;
	motion.zVelocity += zVel;

}

void Targetable::bump(const sf::Vector2f& force, float zVel, Targetable* targ)
{
	bump(force, zVel);
}

void Targetable::launch(const sf::Vector2f& force, float zVel)
{
	active = false;
	motion.velocity += force;
	motion.zVelocity += zVel;
}

void Targetable::launch(const sf::Vector2f& force, float zVel, Targetable* targ)
{
	launch(force, zVel);
}

void Targetable::damage(float amount)
{
}

void Targetable::damage(float amount, Targetable* targ)
{
	damage(amount);
}