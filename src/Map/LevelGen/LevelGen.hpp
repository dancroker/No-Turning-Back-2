#pragma once
#include "Level.hpp"
#include <vector>
#include <iostream>
class LevelGen
{
public:
	LevelGen();
	~LevelGen();

	void generateLevels(int number_of_levels);
	void printMap();
	std::vector< std::vector <int>>& getLevelLayout(int section);

private:
	std::vector<Level> map;
};
