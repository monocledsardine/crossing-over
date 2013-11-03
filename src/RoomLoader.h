#ifndef _ROOMLOADER_H
#define _ROOMLOADER_H

#include <SFML\Graphics.hpp>
#include <deque>
#include "TextureStore.h"

class TileSheet :
	public sf::Sprite
{
public:
	TileSheet();
	TileSheet(const sf::Texture&);
	TileSheet(const sf::Texture&, const sf::Vector2i&, const sf::Vector2i&);

	// Resets tiles to given offset and proportion
	void resetTiles(const sf::Vector2i& proportions, 
		const sf::Vector2i& offset=sf::Vector2i(0,0), 
		const sf::Vector2i& spacing=sf::Vector2i(0,0));

	// Set the displayed image to a specific tile and return for drawing
	const TileSheet& getTile(unsigned);

	// Get the size of a tile
	sf::Vector2u getTileSize(unsigned n=0) const;

	virtual ~TileSheet(void);
private:
	std::deque<sf::IntRect> tiles;
};

///////////////////////////////////////////////////////////////////
/////
/////	Background: A RenderTexture to be drawn to using a  
/////		TileSheet.
/////
///////////////////////////////////////////////////////////////////
class Background :
	public sf::RenderTexture
{
public :
	Background(unsigned width, unsigned height);

	// Get the index of the tile at a position
	int getTileIndex(const sf::Vector2i&) const;

	// Render the texture using a given TileSheet
	void render(TileSheet&);

	// Render one tile to the background using a given TileSheet
	void render(int tile, TileSheet&);

	// Set the tileMap from an array terminated by a negative number or by size
	void setTileMap(int*, int size);

	// Set the nth tile to a specific value
	void setTile(int, int);

	virtual ~Background();
private :
	std::deque<int> tileMap;
};
#endif // _ROOMLOADER_H