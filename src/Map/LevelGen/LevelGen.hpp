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
	void generateHiddenLevels(std::string level_name);
	void printMap();
	void printHiddenMap();
	std::vector< std::vector <int>>& getLevelLayout(int section, bool hidden);
	int amountOfLevels();
	void unlockHiddenLevelSection(int section);

	std::vector<Level>& getMap();
	std::vector<Level>& getHiddenMap(){return hidden_map;};

private:
	std::vector<Level> map;
	std::vector<Level> hidden_map;
	std::filesystem::path start_level = "data/levels/Start";
	std::filesystem::path middle_level = "data/levels/Middle";
	std::filesystem::path middle_hidden_level = "data/levels/MiddleHidden";
	std::filesystem::path end_level = "data/levels/End";
	void generateSectionOfLevel(int number_of_levels, std::filesystem::path file_path);
};
