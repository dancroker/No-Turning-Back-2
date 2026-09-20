#include "GameMap.hpp"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::generate(int level_count)
{
	level.generateLevels(level_count);
}

void GameMap::draw_map(sf::RenderWindow& window)
{
	for (int i = 0; i < level.amountOfLevels(); i++)
	{
		map_draw.draw(level.getLevelLayout(i), window, (level.getLevelLayout(i).size() * tile_size)*i, tile_size);
	}
}

