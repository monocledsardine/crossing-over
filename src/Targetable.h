#ifndef _TARGETABLE_H
#define _TARGETABLE_H

#include "Actor.h"

////////////////////////// INTERFACE ///////////////////////////
/////					
///// Targetable: An Actor capable of being targeted and 
/////	interacted with by game standards.
/////
////////////////////////////////////////////////////////////////
class Targetable :
	public Actor
{
public:
	Targetable(Director& d) :
		Actor(d) {}

	// Displace the object a bit
	virtual void bump(const sf::Vector2f&, float);
	virtual void bump(const sf::Vector2f&, float, Targetable*);

	// Propel the object at great speed
	virtual void launch(const sf::Vector2f&, float);
	virtual void launch(const sf::Vector2f&, float, Targetable*);

	// Damage the object
	virtual void damage(float);
	virtual void damage(float, Targetable*);

	bool isTargetable() { return active; }

	virtual ~Targetable() {}
protected:
	bool active;
};

////////////////////////// INTERFACE ///////////////////////////
/////					
///// Targetor: An Targetable capable of initiating interactions
/////
////////////////////////////////////////////////////////////////
class Targetor :
	public Targetable
{
public:
	Targetor(Director& d) :
		Targetable(d) { targetStatus = NONE; }
	
	virtual void target(Targetable* t) { targetObj=t; targetStatus=OBJECT; }
	
	virtual void target(const sf::Vector2f& p) { targetPos=p; targetStatus=POSITION; }
	
	virtual void clearTarget() { targetStatus=NONE; }
	
	virtual ~Targetor() {}
protected:
	enum STATUS { NONE, OBJECT, POSITION } targetStatus;
	
	Targetable* targetObj;
	
	sf::Vector2f targetPos;
};

#endif //_TARGETABLE_H