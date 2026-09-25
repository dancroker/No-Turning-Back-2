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
	spawn_stars();
}

void GameMap::draw_map(sf::RenderWindow& window)
{
	for (int i = 0; i < level.amountOfLevels(); i++)
	{
		map_draw.draw(level.getLevelLayout(i, false), window, (level.getLevelLayout(i, false).size() * tile_size)*i, tile_size, scroll_amount, false);
		map_draw.draw(level.getLevelLayout(i, true), window, (level.getLevelLayout(i, true).size() * tile_size) * i, tile_size, scroll_amount, true);
	}
	for (star_struct& star : stars)
	{
		//star.star.getHitbox().setPosition({ star.position.x, star.position.y });
		window.draw(star.sprite);		
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

void GameMap::spawn_stars()
{
	for (int i = 0; i < getLevelGen().amountOfLevels(); ++i) {
		auto& design = getLevelGen().getLevelLayout(i, false); 
		for (size_t y = 0; y < design.size(); ++y) {
			for (size_t x = 0; x < design[y].size(); ++x) {
				int tile = design[y][x];
				if (tile == 2) 
				{
					star_struct new_star(star_texture);
					new_star.sprite.setPosition({ x * tile_size, y * tile_size });
					stars.push_back(new_star);
				}
			}
		}
	}
	std::cout << stars.size() << " stars spawned." << std::endl;
}

int GameMap::starCollison(sf::FloatRect player_hitbox)
{
	for (size_t i = 0; i < stars.size(); ++i) {
		if (stars[i].sprite.getGlobalBounds().findIntersection(player_hitbox)) 
		{
			std::cout << "Star collected!" << std::endl;
			unlockHiddenLevelSection(stars[i].level_section);
			stars.erase(stars.begin() + i);
			std::cout << stars.size() << " stars remaining." << std::endl;
			return 1; // Return 1 to indicate a star was collected
		}
	}
	return 0;
}

std::vector<std::vector<int>>& GameMap::getLevelLayout(int section, bool hidden)
{
	return level.getLevelLayout(section, hidden);
}
