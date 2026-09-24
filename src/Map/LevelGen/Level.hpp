#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "../../GameObjects/Star.hpp"
class Level
{
public:
	Level();
	~Level();

	void loadFile(std::string adress);
	void generate(std::string adress);
	int getTile(int x, int y);
	int getWidth();
	int getHeight();
	void clearLevel(int section);
	std::vector< std::vector<int>>& getDesign();

	Star& getStar() { return star; }

private:
	std::vector< std::vector<int> > level_layout;

	Star star;
};
