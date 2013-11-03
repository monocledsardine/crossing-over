#include "TextureStore.h"


TextureStore::TextureStore()
{

}

std::string TextureStore::getFile(TextureStore::ResourceName r)
{
	switch (r) 
	{
	case TS_TEST :			return "images/throwaway_tile.png";
	case SPR_SHOOTER:		return "images/shooter.png";
	case SPR_THROWER:		return "images/thrower.png";
	case SPR_ARROW:			return "images/arrow.png";
	case SPR_SHADOW:		return "images/shadow.png";
	case UNDEFINED :		return "";
	default :				return "";
	}	
}

sf::Texture* TextureStore::get(TextureStore::ResourceName rn) const
{
	return textures.at(rn);
}

sf::Texture& TextureStore::load(TextureStore::ResourceName rn)
{
	sf::Texture* toLoad = new sf::Texture();
	toLoad->loadFromFile(getFile(rn));
	textures[rn] = toLoad;
	return *toLoad;
}

void TextureStore::unload(TextureStore::ResourceName rn)
{
	delete textures[rn];
	textures.erase(rn);
}

void TextureStore::clear()
{
	for (std::map<TextureStore::ResourceName, sf::Texture*>::iterator i=textures.begin(); i != textures.end(); ++i)
	{
		delete i->second;
	}
	textures.clear();
}

TextureStore::~TextureStore()
{
	for (std::map<TextureStore::ResourceName, sf::Texture*>::iterator i=textures.begin(); i != textures.end(); ++i)
	{
		delete i->second;
	}
}
