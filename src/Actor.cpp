#include "Actor.h"

sf::Texture* Actor::shadowTexture;

Actor::Actor(Director& d) : director(d), mask(0,0,32,32)
{ 
	active = true;
	shadow.setSource(this); 
}
Actor::Actor(Director& d, const sf::Vector2f& pos) : director(d)
{ 
	active = true;
	setPosition(pos); 
	shadow.setSource(this); 
}

Actor::Actor(Director& d, float x, float y) : director(d)
{ 
	setPosition(sf::Vector2f(x,y)); shadow.setSource(this); 
}

void Actor::setPosition(const sf::Vector2f& pos) 
{ 
	sf::Transformable::setPosition(pos); 
	mask.left=pos.x; mask.top=pos.y; 
	shadow.setPosition(getPosition());
}

void Actor::update(const sf::Time& time) 
{ 
	beginStep(time);

	setPosition(getPosition() + motion.velocity*time.asSeconds());
	
	z += motion.zVelocity*time.asSeconds();

	if (z < 0)
	{
		land();
	} else if (z > 0) 
	{
		motion.applyGravity();
		motion.applyFriction();
		motion.applyMaxSpeed();
	}

	shadow.setPosition(getPosition());

	//virtual function call
	endStep(time);
}

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shadow);

	states.transform.translate(0, -z*0.5);
	target.draw((sf::Sprite)*this, states);
}