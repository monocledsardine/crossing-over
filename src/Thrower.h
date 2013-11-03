#ifndef _THROWER_H
#define _THROWER_H

#include <SFML\Graphics.hpp>
#include "soul.h"
class Thrower :
	public Soul
{
public:
	Thrower(Director&);
	virtual ~Thrower(void);

	virtual void beginStep(const sf::Time&) {}
	virtual void endStep(const sf::Time&) {}

	static sf::Texture* texture;
};

#endif //_THROWER_H