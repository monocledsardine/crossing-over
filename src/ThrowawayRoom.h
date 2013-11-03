#ifndef _THROWAWAYROOM_H
#define _THROWAWAYROOM_H

// Stuff that has to be here
#include <SFML\Graphics.hpp>

// variables for the tileset - change the inside of the parentheses to alter (X,Y) values for each
sf::Vector2i tileProportions(32, 32);
sf::Vector2i tileOffset(10, 19);
sf::Vector2i tileSpacing(6, 16);

// Width and height of the room, in number of tiles
int roomWidth = 8;
int roomHeight = 3;

// Map of indeces of tiles. Tile index starts at 1 and increments horizontally, looping down over rows
int map[] = { 		
0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1,
2, 2, 2, 2, 2, 2, 2, 2,
-1 };

#endif