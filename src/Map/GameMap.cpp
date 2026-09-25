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
		map_draw.draw(level.getLevelLayout(i, false), window, (level.getLevelLayout(i, false).size() * tile_size)*i, tile_size, scroll_amount, false);
		map_draw.draw(level.getLevelLayout(i, true), window, (level.getLevelLayout(i, true).size() * tile_size) * i, tile_size, scroll_amount, true);
	}
	for (star_struct& star : stars)
	{
		star.star.getHitbox().setPosition({ star.position.x, star.position.y });
		window.draw(star.star.getSprite());
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
				if (design[y][x] == 2) 
				{ // Assuming 2 represents a star tile
					//GameObject star;
					//star.setTexture("data/images/star.png");
					//star.getHitbox().setSize(sf::Vector2f(tile_size, tile_size));
					//star.getHitbox().setPosition({ x * tile_size, y * tile_size });
					//stars.push_back(star);

					star_struct new_star;
					new_star.star.setTexture("data/images/star.png");
					new_star.star.getHitbox().setSize(sf::Vector2f(tile_size, tile_size));
					new_star.level_section = i;
					new_star.position = { x * tile_size, y * tile_size };
					
				}
			}
		}
	}
	std::cout << stars.size() << " stars spawned." << std::endl;
}

std::vector<std::vector<int>>& GameMap::getLevelLayout(int section, bool hidden)
{
	return level.getLevelLayout(section, hidden);
}
