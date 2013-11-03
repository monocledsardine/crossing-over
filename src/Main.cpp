#include <SFML/Graphics.hpp>
#include "Throwaway.h"
#include <string>
#include <io.h>

bool initSprites(TextureStore& store)
{
	Shooter::texture = store.get(store.SPR_SHOOTER);
	Arrow::texture = store.get(store.SPR_ARROW);

	Thrower::texture = store.get(store.SPR_THROWER);
	
	Kirby::texture = store.get(store.SPR_KIRBY);
	
	Enemy::texture = store.get(store.SPR_ENEMY);

	Actor::shadowTexture = store.get(store.SPR_SHADOW);

	return true;
}

//Main
int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML window");
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	sf::Color screenColor(155,155,155);
	//Display while loading
	window.clear(screenColor);
	window.display();

	sf::Clock clock;

	// Load textures
	TextureStore store;
	store.loadAll();
	if (!initSprites(store))
		return -1;

	// Create backgrond
	#include "ThrowawayRoom.h"

	TileSheet* ts = new TileSheet(*store.get(store.TS_TEST));
	ts->resetTiles(tileProportions, tileOffset, tileSpacing);
	
	Background bg(roomWidth*tileProportions.x, roomHeight*tileProportions.y);
	bg.setTileMap(map, roomWidth*roomHeight);
	bg.render(*ts);
	bg.display();
		
	sf::Sprite bgSprite(bg.getTexture());

	delete ts;
	store.unload(store.TS_TEST);

	//Game controller objects
	Director director;
	InputReactor reactor(window, director);

	// Add objects
	Soul* shooter = director.addSoul(Director::SHOOTER);
	shooter->setPosition(100,100);

	director.addSoul(Director::THROWER)->setPosition(100,100);

	// Map inputs
	reactor.mapInput(sf::Keyboard::Q, shooter);

	// Stage drawable objects
	Cameraman cameraman;
	director.stage(cameraman);

	clock.restart();

	// Game loop
	while (window.isOpen()){
			

		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type)
			{
			case sf::Event::Closed :
				{
					window.close();
					break;
				}
			case sf::Event::MouseButtonPressed :
				{
					reactor.handleMouse(event.mouseButton);
					break;
				}
			case sf::Event::KeyPressed :
				{
					reactor.handleKey(event.key);
					break;
				}
			};
		}

		//Update stuff
		director.update(clock.restart());

		cameraman.sort();
	
		//Draw stuff
		window.clear(screenColor);
		window.draw(bgSprite);
		window.draw(cameraman);

		window.display();
	}

	return EXIT_SUCCESS;
}