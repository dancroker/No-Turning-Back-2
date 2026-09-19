#include "LevelGen.hpp"

LevelGen::LevelGen()
{
	// Constructor implementation
};
LevelGen::~LevelGen()
{
	// Destructor implementation
};
void LevelGen::generateLevels(int number_of_levels)
{
	if (number_of_levels <= 0)
	{
		std::cerr << "Error: number_of_levels must be greater than 0." << std::endl;
		return;
	}
	if (map.size() > 0)
	{
		map.clear();
	}
	for (int i = 0; i < number_of_levels; ++i)
	{
		Level level;
		level.generate(1);
		map.push_back(level);
	}
};

void LevelGen::printMap()
{
	for (auto& level : map)
	{
		for (int y = 0; y < level.getHeight(); ++y) 
		{
			for (int x = 0; x < level.getWidth(); ++x)
			{
				std::cout << level.getTile(x, y) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};