#pragma once
#include "LevelGen/LevelGen.hpp"
#include "MapDraw/MapDraw.hpp"
#include "../GameObjects/GameObject.hpp"
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
	int getMapSize();
	void spawn_stars();
	std::vector< std::vector <int>>& getLevelLayout(int section, bool hidden);
	LevelGen& getLevelGen() { return level; };
	float getTileSize() { return tile_size; };
private:
	LevelGen level;
	MapDraw map_draw;


	struct star_struct
	{
		GameObject star;
		int level_section;
		sf::Vector2f position;
	};

	std::vector<star_struct> stars;

	float tile_size = 64.0f;
	float max_scroll_amount = 0.0f;
	float scroll_amount = 0.0f;
	float scroll_speed = 1.0f;
	float levels_shown = 4.0f;

public:
	const std::vector<star_struct>& getStars() const { return stars; }
};
