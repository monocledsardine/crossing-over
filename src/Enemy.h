#ifndef _ENEMY_H
#define _ENEMY_H

#include <SFML\Graphics.hpp>
#include "Targetable.h"
class Enemy :
	public Targetor
{
public:
	Enemy(Director& d);

	//Overrides
	virtual void bump(const sf::Vector2f&);
	virtual void damage(float);

	virtual void target(Targetable* targ) {}
	virtual void target(const sf::Vector2i&) {}

	virtual void beginStep(const sf::Time&) {}
	virtual void endStep(const sf::Time&);

	//					~~~~~ GETS ~~~~~
	float getMass()				{ return mass;		}
	float getHealth()			{ return health;	}
	//					~~~~~~~~~~~~~~~~

	virtual ~Enemy(void);

	static sf::Texture* texture;
private:
	float mass;
	float health;
};
#endif // _ENEMY_H