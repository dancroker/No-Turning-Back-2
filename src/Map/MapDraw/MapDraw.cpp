#include "MapDraw.hpp"

MapDraw::MapDraw()
{
}
MapDraw::~MapDraw()
{
}
void MapDraw::draw(const std::vector<std::vector<int>>& layout)
{
	for (int y = 0; y < layout.size(); ++y)
	{
		for (int x = 0; x < layout[y].size(); ++x)
		{
			if (layout[y][x] == tileType::GROUND) 
			{
				std::cout << "(" << calculate_tilemap_value(layout, x, y) << ")";
			}
		}
		std::cout << std::endl;
	}
}

int MapDraw::calculate_tilemap_value(const std::vector<std::vector<int>>& layout, int tile_x, int tile_y)
{
	int tile_value[9] = {128,1,2,64,0,4,32,16,8};
	int tilemap_value = 0;
	int count = 0;
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			if (tile_x+x < 0 || tile_x+x >= layout[0].size() || tile_y + y < 0 || tile_y + y >= layout.size())
			{
				tilemap_value += tile_value[count];
			}
			else if (layout[tile_y+y][tile_x+x] == tileType::GROUND)
			{
				tilemap_value += tile_value[count];
			}
			count++;
		}
	}


	return tilemap_value;
}
