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

	void generate();
	int getTile(int x, int y);

private:
	std::vector< std::vector<int> > level_layout;
	std::string level_name;

};
