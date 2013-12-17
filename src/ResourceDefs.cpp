#include "ResourceDefs.h"

namespace Game
{

Resource::Resource(const (T*)& targ) :
	target(targ)
{
}

Resource::~Resource()
{
	destroy();
}

T& Resource::get()
{
	return *target;
}

void destroy()
{
	delete target;
	target(0);
}

bool isActive() const
{
	// 0 recommended over NULL
	return target != 0;
}	



void ResourceMap::add(ResourceName name, arg)
{
	// We assume that T* is new. This is not, strictly speaking, good practice. 
	TMap.add[new T
	
}

	void remove(ResourceName);
	T& get(ResourceName);
private:
	std::map<ResourceName, Resource<T>> TMap;
}






void load(ResourceName name)
{
	switch (name)
	{
	
	}
}



}