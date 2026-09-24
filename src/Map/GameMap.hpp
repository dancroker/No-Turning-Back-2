#pragma once
#include "LevelGen/LevelGen.hpp"
#include "MapDraw/MapDraw.hpp"
class GameMap
{
public:
	GameMap();
	~GameMap();

	void generate(int level_count);
	void draw_map(sf::RenderWindow& window);
	void update();
	void printMap();
	void unlockHiddenLevelSection(int section);

private:
	LevelGen level;
	MapDraw map_draw;

	float tile_size = 64.0f;
	float max_scroll_amount = 0.0f;
	float scroll_amount = 0.0f;
	float scroll_speed = 1.0f;
	float levels_shown = 4.0f;

};
