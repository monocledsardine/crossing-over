#ifndef _INPUTREACTOR_H
#define _INPUTREACTOR_H

#include "Targetable.h"
#include "Director.h"
#include <SFML\Graphics.hpp>
#include <map>

//TODO: Use smart pointers for Targetors to avoid the nulling problem
class InputReactor
{
public:
	InputReactor(const sf::RenderWindow&, Director&);

	void mapInput(sf::Keyboard::Key, Targetor*);
	void mapInput(sf::Mouse::Button, Targetor*);

	void handleKey(sf::Event::KeyEvent);
	void handleMouse(sf::Event::MouseButtonEvent);

	~InputReactor();

private:	
	void initiateTarget(Targetor*);

	std::map<sf::Keyboard::Key, Targetor*> keys;
	std::map<sf::Mouse::Button, Targetor*> mbs;

	const sf::RenderWindow& window;
	Director& director;
};
#endif // _INPUTREACTOR_H
