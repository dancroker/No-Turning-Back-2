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

private:
	std::vector<Level> map;
};
