#ifndef _ZSPRITE_H
#define _ZSPRITE_H

#include <SFML\Graphics.hpp>

// INTERFACE
class ZSprite :
	public sf::Sprite
{
public:
	ZSprite(void) : z(0.0) {}

	float z;
	float getZ() const { return z; }

	virtual ~ZSprite(void) {}

	bool operator<(const ZSprite& other) const { return getPosition().y < other.getPosition().y; }
};

#endif //_ZSPRITE_H