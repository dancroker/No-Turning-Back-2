#include <iostream>
#include <vector>
#include "LevelGen/Level.hpp"
int main()
{
	std::cout << "Hello, World!" << std::endl;

	std::vector<int>{1, 2, 3};
	Level level;
	level.generate();
	return 0;
}
 