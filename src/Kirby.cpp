#include "Kirby.h"

sf::Texture* Kirby::texture;

Kirby::Kirby(Director& d) :
	Soul(d)
{
	setTexture(*texture);
}


Kirby::~Kirby(void)
{
}
