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
	void generate(int level_selected);
	int getTile(int x, int y);
	int getWidth();
	int getHeight();

private:
	std::vector< std::vector<int> > level_layout;

};
