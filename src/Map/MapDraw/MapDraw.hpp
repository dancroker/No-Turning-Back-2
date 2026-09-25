#pragma once
#include <vector>
#include <iostream>
#include<SFML/Graphics.hpp>

class MapDraw
{
public:
	MapDraw();
	~MapDraw();

	void draw(const std::vector<std::vector<int>>& layout, sf::RenderWindow& window, 
		      float previous_level_size, float tile_size, float scroll_amount, bool draw_hidden);

private:
	int calculate_tilemap_value(const std::vector<std::vector<int>>& layout, int x, int y);
	std::vector<int> get_tilemap_coordinates(int tilemap_value);

	enum tileDirection // U - UP, R - Right, D - Down, L - Left M - Middle
	{
		U = 1,
		UR = 2,
		R = 4,
		DR = 8,
		D = 16,
		DL = 32,
		L = 64,
		UL = 128,
		M = 0,
	};

	//int tiles[256];
	//Need to find efficent way to do tile check, to get the value and convert into tilemap co-ords
	//Will wait till tilemap is added before developing this! :)  

	sf::Texture texture_tilemap{ "./data/images/SquarePlatform_3.png" };
	sf::Sprite sprite_tilemap{ texture_tilemap };

	float tile_map_tile_size = 8.0f;

	enum tileType
	{
		AIR,
		GROUND,
		HIDDEN = 1,
	};

	enum tilemapCoordinates
	{
		ALLGROUND = 255,
		CORNER_ALL = 32+128+2+8,
		CORNER_UR = 2+1+4,
		CORNER_URH = 1 + 4,
		CORNER_DR = 8,
		CORNER_DL = 32,
		CORNER_UL = 128,
	};


};
