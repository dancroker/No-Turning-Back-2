#include "MapDraw.hpp"

MapDraw::MapDraw()
{
}
MapDraw::~MapDraw()
{
}
void MapDraw::draw(const std::vector<std::vector<int>> layout)
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

int MapDraw::calculate_tilemap_value(std::vector<std::vector<int>> layout, int tile_x, int tile_y)
{
	int tile_value[8] = {128,1,2,64,4,32,16,8};
	int tilemap_value = 0;
	int count = 0;
	for (int x = -1; x < 1; x++) 
	{
		for (int y = -1; y < 1; y++)
		{
			if (x+tile_x < 0 || x+tile_x > layout[0].size() || y + tile_y < 0 || y + tile_y > layout.size())
			{
				tilemap_value += tile_value[count];
				tile_value[count] = 0;
				std::cout << "Bye";
			}
			else if (y + tile_y == tile_y && x + tile_x == tile_x)
			{
				count -= 1;
			}
			else if (layout[x + tile_x][y + tile_y]== tileType::GROUND)
			{
				tilemap_value += tile_value[count];
				tile_value[count] = 0;
			}
			count++;
			
		}
	}


	return tilemap_value;
}
