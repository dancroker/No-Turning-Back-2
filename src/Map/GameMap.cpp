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

void GameMap::draw_map(sf::RenderWindow& window)
{
	map_draw.draw(level.getLevelLayout(2),window,0, tile_size);
	map_draw.draw(level.getLevelLayout(1), window, (level.getLevelLayout(1).size()*tile_size), tile_size);
}
