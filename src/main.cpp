#include <iostream>
#include <vector>
#include "LevelGen/LevelGen.hpp"
int main()
{
	std::cout << "Hello, World!" << std::endl;

	std::vector<int>{1, 2, 3};
	LevelGen levelGen;
	levelGen.generateLevels(3);
	levelGen.printMap();
	return 0;
}
 