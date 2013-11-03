#ifndef _RESOURCENAMES_H
#define _RESOURCENAMES_H

#include <string>

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
std::string getFile(ResourceName r)
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
#endif // _RESOURCENAMES_H