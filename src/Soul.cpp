#include "Soul.h"
#include <math.h>

float abs(float num)
{
	return num > 0 ? num : -num;
}

void Soul::endStep(const sf::Time& time)
{
	sf::Vector2f pos = getPosition();
	switch (targetStatus)
	{
	case NONE : break;
	default :
		if (abs(getPosition().x - targetPos.x) < 2)
		{
			setPosition(targetPos.x, getPosition().y);
			motion.velocity.x = 0;
		}
		if (abs(getPosition().y - targetPos.y) < 2)
		{
			setPosition(getPosition().x, targetPos.y);
			motion.velocity.y = 0;
		}

		//hop
		if (z == 0)
		{
			if (motion.velocity.x == 0 && motion.velocity.y == 0)
			{
				motion.zVelocity = 0;
				targetStatus = NONE;
				break;
			} else
				motion.zVelocity = 10;
		} else if (z < 0)
		{
			z = 0;
			motion.zVelocity = 0;
		} else {
			motion.zVelocity -= 1;
		}

		break;
	};
}

void triangulateUnitVelocity(const sf::Vector2f& dist, sf::Vector2f& vel)
{
	if (dist.x == 0)
	{
		vel.y = (dist.y < 0 ? -1 : 1);
		vel.x = 0;		
	}
	else
	{
		float ratio = dist.y / dist.x;
		vel.x = (1.0f / sqrt(ratio*ratio + 1.0f)) * (dist.x < 0 ? -1 : 1);
		vel.y = vel.x*ratio;
	}
}

void Soul::target(const sf::Vector2f& p)
{
	Targetor::target(p);

	triangulateUnitVelocity(targetPos-getPosition(), motion.velocity);

	motion.velocity.x = motion.velocity.x*MAX_SPEED;
	motion.velocity.y = motion.velocity.y*MAX_SPEED;
}

void Soul::target(Targetable* t)
{
	Targetor::target(t);

	targetPos = t->getPosition();

	triangulateUnitVelocity(targetPos-getPosition(), motion.velocity);

	motion.velocity.x = motion.velocity.x*MAX_SPEED;
	motion.velocity.y = motion.velocity.y*MAX_SPEED;
}

Soul::~Soul(void)
{
}
