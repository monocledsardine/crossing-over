#include "Shooter.h"
#include <math.h>

float abs(float num);

sf::Texture* Shooter::texture;

////////////////////////////// Arrow ////////////////////////////////
sf::Texture* Arrow::texture;

Arrow::Arrow(Director& d, Targetable* targ) :
	Actor(d), target(targ)
{
	setTexture(*texture);
	shadow.setTexture(*shadowTexture);

	strength = 5.0;
	motion.velocity.x = -10.0;
	motion.velocity.y = -10.0;
	
	z = 100;
	motion.gravity = 0.01;
}

Arrow::Arrow(Director& d, Targetable* targ, const sf::Vector2f& pos) :
	Actor(d), target(targ)
{
	setTexture(*texture);
	shadow.setTexture(*shadowTexture);

	setPosition(pos);

	strength = 5.0;
	motion.velocity.x = -10.0;
	motion.velocity.y = -10.0;
	
	z = 20;
	motion.gravity = 0.01;
}

void Arrow::contact()
{
	target->bump(3.0f*motion.velocity, 2*motion.zVelocity);
	target->damage(strength);
}

void Arrow::endStep(const sf::Time& time)
{
	if (contains(target->getPosition()))
	{
		contact();
		destroy();
	}	
}

void Arrow::destroy()
{
	active = false;
}
////////////////////////////////////////////////////////////////////

Shooter::Shooter(Director& d) :
	Soul(d)
{
	setTexture(*texture);
	shadow.setTexture(*shadowTexture);
}

void Shooter::shoot(Targetable* target)
{
	if (arrowList.empty())
	{
		arrowList.push_back(Arrow(director, target, getPosition()));
	}
}

void Shooter::endStep(const sf::Time& time)
{
	std::list<Arrow>::iterator iEnd(arrowList.end());
	for (std::list<Arrow>::iterator i(arrowList.begin()); i != iEnd; ++i)
	{
		i->update(time);
		if (!i->getActive())
		{
			arrowList.erase(i);
			break;
		}
	}

	sf::Vector2f pos = getPosition();
	switch (targetStatus)
	{
	case NONE : break;
	case POSITION: 
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
	case OBJECT :
		if ((pos.x-targetPos.x)*(pos.x-targetPos.x) + (pos.y-targetPos.y)*(pos.y-targetPos.y) <= 1600)
		{
			motion.velocity = sf::Vector2f(0,0);
			shoot(targetObj);
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

void Shooter::land()
{
	active = true;
}	

void Shooter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Actor::draw(target, states);

	std::list<Arrow>::const_iterator iEnd(arrowList.end());
	for (std::list<Arrow>::const_iterator i(arrowList.begin()); i != iEnd; ++i)
	{
		target.draw(*i);
	}
}