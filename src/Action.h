#ifndef _ACTION_H
#define _ACTION_H

#include "Actor.h"

class Action
{
public:
	Action();

	virtual void act(float force) = 0;

	virtual void react(float force) = 0;

	virtual bool wasSuccessful();

	Actor& getInstigator();

	Actor& getTarget();

	virtual ~Action() {};
};

#endif //_ACTION_H