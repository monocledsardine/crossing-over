#include "Cameraman.h"


Cameraman::Cameraman(void)
{
}

void Cameraman::addSubject(Actor* x)
{
	subjects.push_back(x);
}

template <typename T> bool PComp(const T * const & a, const T * const & b)
{
   return *a < *b;
}

void Cameraman::sort()
{
	std::sort(subjects.begin(), subjects.end(), PComp<Actor>);
}

void Cameraman::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	contType::const_iterator end(subjects.end());

	// Don't call this without sorting!
	for (contType::const_iterator i=subjects.begin(); i != end; ++i)
	{
		target.draw(**i);
	}
}

Cameraman::~Cameraman(void)
{
}
