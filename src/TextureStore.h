#ifndef _TEXTURESTORE_H
#define _TEXTURESTORE_H

#include <SFML\Graphics.hpp>
#include <map>
#include <string>


// Loads and maintains textures
class TextureStore
{
public:
	enum ResourceName
	{
		TS_TEST, 
		BG_TREE, 
		SPR_SHOOTER, SPR_THROWER, SPR_KIRBY,
		SPR_ARROW,
		SPR_ENEMY,
		SPR_SHADOW,
		UNDEFINED
	};

	//TODO: error handling for files
	std::string getFile(ResourceName r);

	TextureStore();

	// Return the requested Image
	sf::Texture* get(ResourceName) const;

	void loadAll() { for (ResourceName i=TS_TEST; i != UNDEFINED; i=ResourceName(i+1)) load(i); }

	// Load an individual resource
	sf::Texture& load(ResourceName);

	// Unload an individual resource
	void unload(ResourceName); 

	// Unload all resources from memory
	void clear();

	virtual ~TextureStore();
private:
	std::map<ResourceName, sf::Texture*> textures;	
};

#endif // _TEXTURESTORE_H
