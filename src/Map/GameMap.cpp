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
	//for (int i = 0; i < level_count-4; i++)
	//{
	//	max_scroll_amount += (level.getLevelLayout(i, false).size() * tile_size);
	//}
	//level.printHiddenMap();
	//level.printMap();
}

void GameMap::draw_map(sf::RenderWindow& window)
{
	for (int i = 0; i < level.amountOfLevels(); i++)
	{
		map_draw.draw(level.getLevelLayout(i, false), window, (level.getLevelLayout(i, false).size() * tile_size)*i, tile_size, scroll_amount, false);
		map_draw.draw(level.getLevelLayout(i, true), window, (level.getLevelLayout(i, true).size() * tile_size) * i, tile_size, scroll_amount, true);
	}
}

void GameMap::update()
{
		scroll_amount -= scroll_speed;
}

void GameMap::printMap()
{
	std::cout << "---------------------------------------------------------" << std::endl;
	level.printHiddenMap();
}

void GameMap::unlockHiddenLevelSection(int section)
{
	level.unlockHiddenLevelSection(section);
}

int GameMap::getMapSize()
{
	return level.amountOfLevels();
}

std::vector<std::vector<int>>& GameMap::getLevelLayout(int section, bool hidden)
{
	return level.getLevelLayout(section, hidden);
}
