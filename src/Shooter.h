#ifndef _SHOOTER_H
#define _SHOOTER_H

#include "Soul.h"
#include <list>

///////////////////////////////////////////////////////////
////
////	Arrow: Shooter's default projectile weapon. Damages
////		and displaces other Actors slightly.
////
///////////////////////////////////////////////////////////

class Arrow :
	public Actor
{
public:
	Arrow(Director& d, Targetable* targ);
	Arrow(Director& d, Targetable* targ, const sf::Vector2f& pos);

	// Applies damage and bumps the target
	virtual void contact();
	virtual void destroy();

	// Overrides
	virtual void beginStep(const sf::Time&) {}
	virtual void endStep(const sf::Time&);

	virtual ~Arrow() {};

	static sf::Texture* texture;
private:
	// The target to be hit. The arrow cannot hit a non-
	// target
	Targetable* target;

	// The amount of damage done by the arrow
	float strength;
};

////////////////////////////////////////////////////////////////
///// 
///// Shooter: A Soul. Interacts by shooting arrows of some kind.
/////
////////////////////////////////////////////////////////////////

class Shooter :
	public Soul
{
public:
	Shooter(Director& d);

	// Fire an arrow at a target
	void shoot(Targetable* target);

	~Shooter() {}

	static sf::Texture* texture;
protected:
	void beginStep(const sf::Time&) {}
	void endStep(const sf::Time&);
	void land();
private:
	int load;
	std::list<Arrow> arrowList;

	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // _SHOOTER_H
