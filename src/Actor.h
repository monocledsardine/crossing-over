#ifndef _ACTOR_H
#define _ACTOR_H

#include <SFML/Graphics.hpp>
#include "TextureStore.h"
#include "Mask.h"
#include "ZSprite.h"
#include "Shadow.h"
#include "Motion.h"

class Director;

////////////////////////////////////////////////////////////////
///// 
///// Actor: A physical, dynamic object in the game world. 
/////
////////////////////////////////////////////////////////////////

class Actor :
	public ZSprite
{
public: 
	Actor(Director& d);
	Actor(Director& d, const sf::Vector2f& pos);
	Actor(Director& d, float x, float y);

	//						~~~~~~~~
	// Gets
	Director& getDirector() const		{ return director; }

	// Sets
	void setPosition(const sf::Vector2f& pos);
	void setPosition(float x, float y)					{ setPosition(sf::Vector2f(x,y)); }
	//						~~~~~~~~

	bool getActive() { return active;}
	
	
	// Returns whether a point is contained in the object's mask
	bool contains(const sf::Vector2i& point) const { return mask.contains(sf::Vector2f(point)); }
	bool contains(const sf::Vector2f& point) const { return mask.contains(point); }

	// The quintessential frame-step function.
	void update(const sf::Time& time);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual ~Actor() {}
	
	Motion motion;
	static sf::Texture* shadowTexture;
protected:
	bool active;
	Shadow shadow;

	//Called at the beginning of the update function
	virtual void beginStep(const sf::Time& time) {};

	//Called at the end of the update function
	virtual void endStep(const sf::Time& time) {};

	// Land on the ground
	virtual void land() {}

	// An Actor without a director is lost! This is a required field
	Director& director;

	// The collision mask of the object. Includes absolute location 
	// as well as relative location of the object.
	sf::FloatRect mask;
};
#endif //_ACTOR_H