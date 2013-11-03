#ifndef _KIRBY_H
#define _KIRBY_H

#include <SFML\Graphics.hpp>
#include "soul.h"
class Kirby :
	public Soul
{
public:
	Kirby(Director&);
	virtual ~Kirby(void);

	virtual void beginStep(const sf::Time&) {}
	virtual void endStep(const sf::Time&) {}

	static sf::Texture* texture;
};
#endif // _KIRBY_H
