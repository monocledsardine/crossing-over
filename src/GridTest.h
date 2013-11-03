#ifndef _GRIDTEST_H
#define _GRIDTEST_H

#include <SFML/Graphics.hpp>

//Header

class Grid
{
private:
	int tileHeight, tileWidth;
	sf::IntRect bounds;

public:
	Grid(int, int, sf::IntRect);
	
	/* Returns the tile underneath a point */
	virtual sf::IntRect getTile(sf::Vector2f);
	
	virtual sf::IntRect getTile(sf::Vector2i);
	
	/* Returns the x value of the underlying tile*/
	virtual int getTileX(int);
	
	/* Returns the y value of the underlying tile*/
	virtual int getTileY(int);
	
	/* Debug purposes only */
	void draw(sf::RenderTarget& target, sf::RenderStates states);		

	~Grid(void);
};
#endif // _GRIDTEST_H