#ifndef _CAMERAMAN_H
#define _CAMERAMAN_H

#include <SFML\Graphics.hpp>
#include <deque>
#include "ZSprite.h"

class Cameraman : 
	public sf::Drawable
{
public:
	Cameraman(void);
	void addSubject(ZSprite*);
	void sort();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~Cameraman(void);

private:
	typedef std::deque<ZSprite*> contType;
	contType subjects;
};
#endif // _CAMERAMAN_H