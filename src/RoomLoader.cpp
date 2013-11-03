#include "RoomLoader.h"

////////////////////////////////////// TileSheet //////////////////////////////////
// ***************************************************************************** //

TileSheet::TileSheet() :
	Sprite()
{
}

TileSheet::TileSheet(const sf::Texture& texture) :
	Sprite(texture)
{
}

TileSheet::TileSheet(const sf::Texture& texture, const sf::Vector2i& offset, const sf::Vector2i& props) :
	Sprite(texture)
{
	resetTiles(offset, props);
}

void TileSheet::resetTiles(const sf::Vector2i& proportions, const sf::Vector2i& offset, const sf::Vector2i& spacing)
{
	// start fresh
	tiles.clear();

	const sf::Vector2u fullSize = getTexture()->getSize();
	// int automatically rounds down the floating points
	const int numHorizontal = (fullSize.x- offset.x) / (proportions.x + spacing.x);
	const int numVertical = (fullSize.y - offset.y) / (proportions.y + spacing.y);
	
	if (numHorizontal <= 0 || numVertical <= 0)
		return;

	// initialize all tiles to the correct proportions
	tiles.resize(numHorizontal*numVertical, sf::IntRect(0, 0, proportions.x, proportions.y));

	// Set origin points
	int inc=0;
	for (std::deque<sf::IntRect>::iterator i=tiles.begin(); i != tiles.end(); ++i)
	{
		i->left = (inc % numHorizontal)*(proportions.x + spacing.x) + offset.x;
		i->top = (inc / numHorizontal)*(proportions.y + spacing.y) + offset.y;
		++inc;
	}
}

const TileSheet& TileSheet::getTile(unsigned i)
{
	if (i < tiles.size())
	{
		setTextureRect(tiles[i]);
	}
	return *this;
}

sf::Vector2u TileSheet::getTileSize(unsigned n) const
{
	return sf::Vector2u(tiles[n].width, tiles[n].height);
}

TileSheet::~TileSheet(void)
{
}



////////////////////////////////////// Background /////////////////////////////////
// ***************************************************************************** //

Background::Background(unsigned width, unsigned height)
{
	create(width, height);
	initialize();
}

void Background::render(TileSheet& sheet)
{
	clear(sf::Color(0,0,0,0));

	sf::Vector2u props = sheet.getTileSize();
	int renderX=0;
	int renderY=0;

	for (int i=0; i < tileMap.size(); ++i)
	{
		sheet.setPosition(renderX, renderY);
		int val(tileMap[i]);
		if (val > 0)
			draw(sheet.getTile(val - 1));
		
		renderX += props.x;
		
		if (renderX >= getSize().x)
		{
			renderX = 0;
			renderY += props.y;
		}

		if (renderY > getSize().y)
			return;
	}
}

void Background::render(int tile, TileSheet& sheet)
{
	sf::Vector2u props = sheet.getTileSize();
	int renderX = (tile % (getSize().x/props.x)) * props.x;
	int renderY = (tile / (getSize().x/props.x)) * props.y;

	sheet.setPosition((float)renderX, (float)renderY);
	draw(sheet.getTile(tileMap[tile]));
}

void Background::setTileMap(int* args, int size)
{
	tileMap.resize(size);
	for (int i=0; args[i] >= 0 && i < tileMap.size(); ++i)
	{
		tileMap[i] = args[i];
	}
}

void Background::setTile(int location, int tileInd)
{
	if (location >= 0 && location < tileMap.size())
		tileMap[location] = tileInd;
}

Background::~Background()
{
}