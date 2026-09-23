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
	for (int i = 0; i < level_count-4; i++)
	{
		max_scroll_amount += (level.getLevelLayout(i, false).size() * tile_size);
	}
	level.printHiddenMap();
}

void GameMap::draw_map(sf::RenderWindow& window)
{
	for (int i = 0; i < level.amountOfLevels(); i++)
	{
		map_draw.draw(level.getLevelLayout(i, false), window, (level.getLevelLayout(i, false).size() * tile_size)*i, tile_size, scroll_amount, false);
		if (i < level.amountOfLevels() - 1 && i > 0)
		{
			map_draw.draw(level.getLevelLayout(i-1, true), window, (level.getLevelLayout(i-1, true).size() * tile_size) * i, tile_size, scroll_amount, true);
		}
	}
}

void GameMap::update()
{
	if (max_scroll_amount > scroll_amount)
	{
		scroll_amount += scroll_speed;
	}
}

