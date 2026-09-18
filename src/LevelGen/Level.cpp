#include "Level.hpp"

Level::Level()
{
	// Constructor implementation
};
Level::~Level()
{
	// Destructor implementation
};

void Level::generate()
{
	std::ifstream f("./data/levels/Level_1.txt");

    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
    }

    std::string s;

    // Read each line from the file
    while (std::getline(f, s))
        std::cout << s << std::endl;

    // Close the file
    f.close();


};

int Level::getTile(int x, int y)
{
	return 0;
};