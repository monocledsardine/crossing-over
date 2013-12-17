#ifndef _SHADOW_H
#define _SHADOW_H

#include <SFML\Graphics.hpp>
#include "Actor.h"

class Actor;
////////////////////////////////////////////////////////////////
///// 
///// Shadowable: has a drawable shadow attached to it 
/////
////////////////////////////////////////////////////////////////
class Shadow : 
	public sf::Sprite
{
public:
	Shadow() {}
	Shadow(Actor* source) : source(source) {}

	void setSource(Actor* src)
	{
		source = src;
	}

	virtual ~Shadow() {}
private:
	Actor* source;
};
#endif // _SHADOW_H