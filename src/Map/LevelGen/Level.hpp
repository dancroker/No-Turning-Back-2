#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
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
	std::vector< std::vector<int>>& getDesign();

private:
	std::vector< std::vector<int> > level_layout;

};
