#ifndef IMAGEREF_H
#define IMAGEREF_H

#include "TiledImage.h"
#include <string>

struct ImageRef
{
public:
	enum name 
	{	
		ABS				=0,
		ABS_RUN_D		=1,
		ABS_RUN_DL		=2,
		ABS_RUN_DR		=3,
		ABS_RUN_L		=4,
		ABS_RUN_R		=5,
		ABS_RUN_U		=6,
		ABS_RUN_UL		=7,
		ABS_RUN_UR		=8,
		ARROW			=9,
		CURSOR			=10,
		DEATH			=11,
		DEATH_WALK_D	=12,
		DEATH_WALK_L	=13,
		DEATH_WALK_R	=14,
		DEATH_WALK_U	=15,
		ENEMY1			=16,
		KIRBY			=17,
		NPC1			=18,
		SHADOW			=19,
		SHOOTER			=20,
		TARGET_GROUND	=21,
		TARGETS			=22,
		THROWAWAY_2		=23,
		THROWAWAY_TILE	=24,
		THROWER			=25,
		WATER_1			=26
	};
	
	std::map<name, TiledImage> images;
	
	ImageRef()
	{
		images.push_back(	ABS, 			
							TiledImage(find("Abs.png"), 		
							TileParams());
		images.push_back(	ABS_RUN_D, 	
							TiledImage(find("abs_run_d.png"), 	
							TileParams());
		images.push_back(	ABS_RUN_DL, 	
							TiledImage(find("abs_run_dl.png"), 
							TileParams());
		images.push_back(	ABS_RUN_DR,	
							TiledImage(find("abs_run_dr.png"), 
							TileParams());
		images.push_back(	ABS_RUN_L, 	
							TiledImage(find("abs_run_l.png"), 	
							TileParams());
		images.push_back(	ABS_RUN_R, 	
							TiledImage(find("abs_run_r.png"), 	
							TileParams());
		images.push_back(	ABS_RUN_U, 	
							TiledImage(find("abs_run_u.png"), 	
							TileParams());
		images.push_back(	ABS_RUN_UL, 	
							TiledImage(find("abs_run_ul.png"), 
							TileParams());
		images.push_back(	ABS_RUN_UR, 	
							TiledImage(find("abs_run_ur.png"), 
							TileParams());
		images.push_back(	ARROW,			
							TiledImage(find("arrow.png"), 	
							TileParams());
		images.push_back(	CURSOR,		
							TiledImage(find("cursor.png"), 	
							TileParams());
		images.push_back(	DEATH,			
							TiledImage(find("death.png"), 	
							TileParams());
		images.push_back(	DEATH_WALK_D,	
							TiledImage(find("Death_walk_d.png"), 	
							TileParams());
		images.push_back(	DEATH_WALK_L,	
							TiledImage(find("death_walk_l.png"), 	
							TileParams());
		images.push_back(	DEATH_WALK_R,	
							TiledImage(find("death_walk_r.png"), 	
							TileParams());
		images.push_back(	DEATH_WALK_U,	
							TiledImage(find("death_walk_u.png"), 	
							TileParams());
		images.push_back(	ENEMY1,		
							TiledImage(find("enemy1.png"), 	
							TileParams());
		images.push_back(	KIRBY,			
							TiledImage(find("kirby.png"), 	
							TileParams());
		images.push_back(	NPC1,			
							TiledImage(find("npc1.png"), 	
							TileParams());
		images.push_back(	SHADOW,		
							TiledImage(find("shadow.png"), 	
							TileParams());
		images.push_back(	SHOOTER,		
							TiledImage(find("shooter.png"), 	
							TileParams());
		images.push_back(	TARGET_GROUND,	
							TiledImage(find("target ground.png"), 	
							TileParams());
		images.push_back(	TARGETS,		
							TiledImage(find("targets.png"), 	
							TileParams());
		images.push_back(	THROWAWAY_2,	
							TiledImage(find("Throwaway 2.png"), 	
							TileParams());
		images.push_back(	THROWAWAY_TILE,
							TiledImage(find("throwaway_tile.png"), 	
							TileParams());
		images.push_back(	THROWER,		
							TiledImage(find("thrower.png"), 	
							TileParams());
		images.push_back(	WATER_1,		
							TiledImage(find("water 1.png"), 	
							TileParams());
		}
	
	std::string find(const std::string file) const { return "images/" + file; }
};

#endif //IMAGEREF_H