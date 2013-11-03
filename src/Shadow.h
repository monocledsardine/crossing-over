#ifndef _SHADOW_H
#define _SHADOW_H

#include <SFML\Graphics.hpp>
#include "ZSprite.h"


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
	Shadow(ZSprite* source) : source(source) {}

	void setSource(ZSprite* src)
	{
		source = src;
	}

	virtual ~Shadow() {}
private:
	ZSprite* source;
};
#endif // _SHADOW_H