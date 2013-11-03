#include "InputReactor.h"


InputReactor::InputReactor(const sf::RenderWindow& wind, Director& d) :
	window(wind), director(d)
{
}

void InputReactor::mapInput(sf::Keyboard::Key inp, Targetor* targ)
{
	keys[inp] = targ;
}

void InputReactor::mapInput(sf::Mouse::Button inp, Targetor* targ)
{
	mbs[inp] = targ;
}

void InputReactor::handleKey(sf::Event::KeyEvent e)
{
	if (keys.count(e.code))
		{
			initiateTarget(keys[e.code]);
			return;
		}
}

void InputReactor::handleMouse(sf::Event::MouseButtonEvent e)
{
	if (mbs.count(e.button))
		{
			initiateTarget(mbs[e.button]);
			return;
		}
}

InputReactor::~InputReactor()
{
}


void InputReactor::initiateTarget(Targetor* targ)
{
	Targetable* result;
	float minZ=-1;

	const sf::Vector2f mp(sf::Mouse::getPosition(window));

	// Try to find a Soul under the mouse 
	if (!director.souls.empty())
		for (Director::soulMap::iterator x=director.souls.begin(); x != director.souls.end(); ++x)
		{
			Soul* s = x->second;
			if (s->contains(mp))
			{
				if (minZ == -1 || s->getZ() < minZ)
				{
					result = s;
					minZ = s->getZ();
				}
			}
		}
	
	// Stop if a soul has been targeted
	if (minZ != -1)
	{
		targ->target(result);
		return;
	}

	// Try to find an enemy
	if (!director.enemies.empty())
		for (Director::enemyMap::iterator x=director.enemies.begin(); x != director.enemies.end(); ++x)
		{
			Enemy* e = x->second;
			if (e->contains(mp))
			{
				if (minZ == -1 || e->getZ() < minZ)
				{
					result = e;
					minZ = e->getZ();
				}
			}
		}

	if (minZ != -1)
	{
		targ->target(result);
		return;
	}

	// Target a location otherwise
	targ->target(mp);
	return;
}