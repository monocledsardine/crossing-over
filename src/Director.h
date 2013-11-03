#ifndef _DIRECTOR_H
#define _DIRECTOR_H

#include "Enemy.h"
#include "Shooter.h"
#include "Thrower.h"
#include "Kirby.h"
#include "Cameraman.h"
#include <deque>

// TODO: Use smart pointers
// Maybe Director and Actor should be friends

////////////////////////////////////////////////////////////////
///// 
///// Director: Creates, stores, and allows access to Actors.
/////	Also provides easy iterative operations such as update.
/////
////////////////////////////////////////////////////////////////
class Director
{
public:
	enum SoulType { SHOOTER, THROWER, KIRBY };
	enum EnemyType { GENERIC };
	enum CharacterType { DEATH, ABBY };

	typedef std::map<SoulType, Soul*> soulMap;
	typedef pair<SoulType, Soul*> soulPair;

	typedef std::multimap<EnemyType, Enemy*> enemyMap;
	typedef pair<EnemyType, Enemy*> enemyPair;


	Director();

	// Construction
	
	Soul* addSoul(SoulType);
	Enemy* addEnemy(EnemyType);
	//Character* addCharacter(CharacterType);

	// Updates all contained Actors
	void update(const sf::Time&);

	// Instruct a cameraman to stage all contained Actors for filming
	void stage(Cameraman&);
	
	//////////////////////// Inline //////////////////////////////////
	// Iterative access
	soulMap::const_iterator soulIt() { return souls.begin(); }
	enemyMap::const_iterator enemyIt() { return enemies.begin(); }

	// Specific access
	Soul* getSoul(SoulType t) { return souls.at(t); }

	enemyMap::const_iterator enemiesBegin(EnemyType t) { return enemies.lower_bound(t); }
	enemyMap::const_iterator enemiesEnd(EnemyType t) { return enemies.upper_bound(t); }
	//////////////////////////////////////////////////////////////////

	// Removes individual objects from storage
	void destroy(SoulType);
	void destroy(soulMap::iterator);
	void destroy(enemyMap::iterator);

	~Director();

	soulMap souls;
	enemyMap enemies;
};
#endif // _DIRECTOR_H