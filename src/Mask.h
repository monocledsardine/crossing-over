#ifndef _MASK_H
#define _MASK_H

#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;

class Mask :
	public sf::Transformable, public sf::Drawable
{
private: 
	vector<sf::FloatRect> restMask;
public:
	Mask() 
	{
		restMask.push_back(sf::FloatRect(0, 0, 20, 20));
	}

	Mask(sf::FloatRect rect)
	{
		restMask.push_back(rect);
	}

	void addRect(float left, float top, float width, float height)
	{
		restMask.push_back(sf::FloatRect(left, top, width, height));
	}

	sf::FloatRect getRect(int n)
	{
		return restMask.at(n);
	}

	int size()
	{
		return restMask.size();
	}

	bool contains(const sf::Vector2f& point) const
	{
		//TODO: take into account transformations
		for (unsigned i=0; i<restMask.size(); ++i) 
			if (restMask.at(i).contains(point))
				return true;
		return false;
	}

	bool contains(const sf::Vector2i& point) const
	{
		sf::Vector2f p((float)point.x, (float)point.y);
		return contains(p);
	}

	/* Check if the mask intersects a rectangle */
	virtual bool intersects(const sf::FloatRect& rect) const
	{
		//TODO: take into account transformations
		for (unsigned i=0; i<restMask.size(); ++i) 
			if (restMask.at(i).intersects(rect))
				return true;
		return false;
	}

	bool intersects(const sf::IntRect& rect) const
	{
		sf::FloatRect r((float)rect.left, (float)rect.top, (float)rect.width, (float)rect.height);
		return intersects(r);
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		sf::RectangleShape r(sf::Vector2f(0.0f, 0.0f));
		int j=restMask.size();

		states.transform *= getTransform();

		for (int i=0; i<j; ++i) 
		{
			r.setSize(sf::Vector2f(restMask.at(i).width, restMask.at(i).height));
			
			target.draw(r, states);
		}
	}
};
#endif // _MASK_H