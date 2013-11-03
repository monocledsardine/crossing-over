#include "Director.h"

Director::Director()
{
}

Soul* Director::addSoul(SoulType t)
{
	Soul* toReturn;

	switch (t)
	{
	case SHOOTER :
		toReturn = new Shooter(*this);
		break;
	case THROWER :
		toReturn = new Thrower(*this);
		break;
	case KIRBY :
		toReturn = new Kirby(*this);
		break;
	default :
		break;
	}

	if (toReturn != 0)
		souls[t] = toReturn;

	return toReturn;
}

Enemy* Director::addEnemy(EnemyType t)
{
	Enemy* toReturn;

	switch (t)
	{
	case GENERIC :
		toReturn = new Enemy(*this);
		break;
	default :
		break;
	}

	if (toReturn != 0)
		enemies.insert(make_pair(t, toReturn));

	return toReturn;

}

void Director::update(const sf::Time& time)
{	
	soulMap::iterator soulEnd(souls.end());
	enemyMap::iterator enemyEnd(enemies.end());

	for (soulMap::iterator i=souls.begin(); i != soulEnd; ++i)
		i->second->update(time);
	for (enemyMap::iterator i=enemies.begin(); i != enemyEnd; ++i)
		i->second->update(time);
}

void Director::stage(Cameraman& man)
{
	soulMap::iterator soulEnd(souls.end());
	enemyMap::iterator enemyEnd(enemies.end());

	for (soulMap::iterator i=souls.begin(); i != soulEnd; ++i)
		man.addSubject(i->second);
	for (enemyMap::iterator i=enemies.begin(); i != enemyEnd; ++i)
		man.addSubject(i->second);

	man.sort();
}

void Director::destroy(SoulType obj)
{
	soulMap::iterator i = souls.find(obj);
	if (i != souls.end())
	{
		delete i->second;
		souls.erase(i);
	}
}

void Director::destroy(soulMap::iterator obj)
{
	destroy(obj->first);
}

void Director::destroy(enemyMap::iterator obj)
{
	typedef enemyMap::iterator EI;
	pair<EI, EI> range = enemies.equal_range(obj->first);

	for (EI i=range.first; i != range.second; ++i)
		if (i->second == obj->second)
		{
			delete i->second;
			enemies.erase(i);
		}
}

Director::~Director(void)
{
	for (soulMap::iterator i=souls.begin(); i != souls.end(); ++i)
		delete i->second;
	for (enemyMap::iterator i=enemies.begin(); i != enemies.end(); ++i)
		delete i->second;
}