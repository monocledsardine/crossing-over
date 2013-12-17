#ifndef RESOURCEDEFS_H
#define RESOURCEDEFS_H

#include <map>
 
/* 	Constructs and maintains a runtime resource of 
	type T. 
*/
template <typename T> class Resource
{
public: 
	//class Constructor
	//{
	//	
	//}
	
	Resource() {}
	
	// Copy T object into target
	Resource(const T&);
	
	// Return target
	T* get();
	
	// Clear target
	void destroy()

	// Does target hold a value
	bool isActive(); const
private:
	~Resource();
	
	// The re-sourced object
	T* target;
};

/*	Bare bones get-set map of Resources */
template <typename T> class ResourceMap
{
	ResourceMap() {}
	void add(ResourceName, construct);
	void remove(ResourceName);
	T* get(ResourceName);
private:
	std::map<ResourceName, Resource<T>> TMap;
};

enum ResourceName {
	//In alphabetical order
	NONE					=0, 
	TXT_ABBY_STAND			, 
	TXT_ABBY_WALK_D			, 
	TXT_ABBY_WALK_DL		,
	TXT_ABBY_WALK_DR		,
	TXT_ABBY_WALK_L			,
	TXT_ABBY_WALK_R			,
	TXT_ABBY_WALK_U			,
	TXT_ABBY_WALK_UL		,
	TXT_ABBY_WALK_UR		,
	TXT_ARROW				,
	TXT_CURSOR				,
	TXT_CURSOR_TARGET		,
	TXT_CURSOR_NUMBER		,
	TXT_DEATH_STAND			,
	TXT_DEATH_WALK_D		,
	TXT_DEATH_WALK_L		,
	TXT_DEATH_WALK_R		,
	TXT_DEATH_WALK_U		,
	TXT_ENEMY1_STAND		,
	TXT_KIRBY_STAND			,
	TXT_NPC1_STAND			,
	TXT_SHADOW				,
	TXT_SHOOTER				,
	TXT_THROWER				,
	
	
	TXT_THROWAWAY_TILE		,
	TXT_WATER_TILE
};

template <typename T> T* load(ResourceName);

} //namespace Game


#endif // RESOURCEDEFS_H










#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H

#include <SFML/Graphics/Texture.hpp>

/* 	Carries data required to construct a Texture from 
	a file.
*/
struct TextureLoadParams
{
	LoadTextureParams() :
		fname(""), isTiled(false) {}

	bool isTiled;
	Grid bounds;
};

/* 	Initializes an sf::Texture using the source and 
	specifications designated by TextureLoadParams.
*/
void loadTexture(sf::Texture&, LoadTextureParams);

#endif // TEXTUREPARAMS_H