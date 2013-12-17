class Actor
{
	Body
	Face sf::Sprite*
	Mind
};

class Body
{
	void update(Actor)=0;
}

class Mind
{
	void update(Actor)=0;
}

class Face
{
	void draw(Actor)=0;
}