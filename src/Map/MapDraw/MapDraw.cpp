#include "MapDraw.hpp"

MapDraw::MapDraw()
{
}
MapDraw::~MapDraw()
{
}
void MapDraw::draw(const std::vector<std::vector<int>>& layout, sf::RenderWindow& window, float previous_level_size, float tile_size, float scroll_amount, bool draw_hidden)
{
	for (int y = 0; y < layout.size(); ++y)
	{
		for (int x = 0; x < layout[y].size(); ++x)
		{
			if (draw_hidden)
			{
				if (layout[y][x] == tileType::HIDDEN)
				{
					sf::RectangleShape tile(sf::Vector2f(tile_size, tile_size));
					//sprite_tilemap.setTextureRect(sf::IntRect({ 0, 0 }, { (int)tile_size, (int)tile_size }));
					float tile_x = x * tile_size;
					float tile_y = (y * tile_size) + previous_level_size + scroll_amount;
					tile.setPosition({ tile_x, tile_y });
					tile.setFillColor(sf::Color::Red);
					window.draw(tile);
				}
			}
			else 
			{
				if (layout[y][x] == tileType::GROUND)
				{
					std::vector<int> tilemap_coordinates = get_tilemap_coordinates(calculate_tilemap_value(layout, x, y));
					sprite_tilemap.setTextureRect(sf::IntRect({ tilemap_coordinates[0], tilemap_coordinates [1]}, {(int)tile_map_tile_size, (int)tile_map_tile_size }));
					float scale_factor =  tile_size / tile_map_tile_size;
					sprite_tilemap.setScale({ scale_factor, scale_factor });
					float tile_x = x * tile_size;
					float tile_y = (y * tile_size) + previous_level_size + scroll_amount;
					sprite_tilemap.setPosition({ tile_x, tile_y });
					window.draw(sprite_tilemap);
				}
			}
		}
		//std::cout << std::endl;
	}
}

int MapDraw::calculate_tilemap_value(const std::vector<std::vector<int>>& layout, int tile_x, int tile_y)
{
	int tile_value[9] = {tileDirection::UL,tileDirection::U,tileDirection::UR,
		                 tileDirection::L,tileDirection::M,tileDirection::R,
		                 tileDirection::DL,tileDirection::D,tileDirection::DR};
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

std::vector<int> MapDraw::get_tilemap_coordinates(int tilemap_value)
{
	return { 3,3 };
}
