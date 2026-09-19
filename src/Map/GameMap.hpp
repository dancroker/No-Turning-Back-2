#pragma once
#include "LevelGen/LevelGen.hpp"
#include "MapDraw/MapDraw.hpp"
class GameMap
{
public:
	GameMap();
	~GameMap();

	void generate();
	void draw_map();

private:
	LevelGen level;
	MapDraw map_draw;

};
