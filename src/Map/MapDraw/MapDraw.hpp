#pragma once
#include <vector>
#include <iostream>
class MapDraw
{
public:
	MapDraw();
	~MapDraw();

	void draw(const std::vector<std::vector<int>> layout);
private:
	int calculate_tilemap_value(std::vector<std::vector<int>> layout, int x, int y);

	enum tileDirection // U - UP, R - Right, D - Down, L - Left
	{
		U = 1,
		UR = 2,
		R = 4,
		DR = 8,
		D = 16,
		DL = 32,
		L = 64,
		UL = 128,
	};


	enum tileType
	{
		AIR,
		GROUND,
	};



};
