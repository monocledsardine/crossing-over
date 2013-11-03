#include "Thrower.h"

sf::Texture* Thrower::texture;

Thrower::Thrower(Director& d) :
	Soul(d)
{
	setTexture(*texture);
}


Thrower::~Thrower(void)
{
}
