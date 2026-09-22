#pragma once
#include "Level.hpp"
#include <vector>
#include <filesystem>
#include <iostream>
class LevelGen
{
public:
	LevelGen();
	~LevelGen();

	void generateLevels(int number_of_levels);
	void printMap();
	std::vector< std::vector <int>>& getLevelLayout(int section);
	int amountOfLevels();

private:
	std::vector<Level> map;
	std::filesystem::path start_level = "data/levels/Start";
	std::filesystem::path middle_level = "data/levels/Middle";
	std::filesystem::path end_level = "data/levels/End";
	void generateSectionOfLevel(int number_of_levels, std::filesystem::path file_path);
};
