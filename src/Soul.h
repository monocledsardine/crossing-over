#ifndef _SOUL_H
#define _SOUL_H

#include "Targetable.h"

////////////////////////////////////////////////////////////////
///// 
///// Soul: A controllable character, capable of targeting and
/////	being targeted by other Actors.
/////
////////////////////////////////////////////////////////////////
class Soul :
	public Targetor
{
public:
	Soul(Director& d) :
	  Targetor(d) {}

	virtual void endStep(const sf::Time& time);

	virtual void target(const sf::Vector2f& p);
	virtual void target(Targetable* t);

	virtual ~Soul();

	static const int MAX_SPEED=180;
};

#endif //_SOUL_H