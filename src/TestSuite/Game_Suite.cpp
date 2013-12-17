#include <iostream>
#include "Suite.h"
#include <SFML/Graphics.hpp>
#include "TextureLoading_Test.h"

#include "../Animation.h"

using namespace std;
using namespace TestSuite;

void runWindow()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");	
	
	Animation anim;
	TiledImage tImage;
	tImage.loadFromFile("test.png");
	tImage.loadTiles(TileSet(TileParams(sf::Vector2u(17, 24), sf::Vector2u(4,0), sf::Vector2u(4, 1)), tImage.getSize().x, tImage.getSize().y));	
	anim.loadFromImage(tImage, sf::seconds(0.1f), false);
	anim.setFrame(0);
	
	sf::Time timer;
	sf::Clock clock;
	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		timer += clock.restart();
		anim.setFrame(anim.getFrame(timer));
		
		window.clear();
		window.draw(anim);
		window.display();
	}
}

int main()
{
	Suite suite("SFML Game Tests");
	suite.addTest(new TextureLoadingTest);
	suite.run();
	long nFail = suite.report();

	runWindow();

	suite.free();
	return nFail;
}
