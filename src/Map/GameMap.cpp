#include "GameMap.hpp"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::generate()
{
	level.generateLevels(3);
}

void GameMap::draw_map()
{
	map_draw.draw(level.getLevelLayout(1));
}
