#include "Level.hpp"

Level::Level()
{
	// Constructor implementation
};
Level::~Level()
{
	// Destructor implementation
};

void Level::loadFile(std::string adress)
{
    std::ifstream f(adress);

    // If the file is not open / failed to load
    if (!f.is_open()) 
    {
        std::cerr << "Error opening the file!";
    }


    std::string string;
    // Read each line from the file
    while (std::getline(f, string))
    {

        int tile_value = 0;
        bool tens = true;
        std::vector<int> row;

        for (char c : string)
        {
            if (c == ',')
            {
                continue;
            }
            if (tens)
            {
                int tile = c - '0';
                tile_value += (tile * 10);
                tens = false;
            }
            else
            {
                int tile = c - '0';
                tile_value += tile;
                row.push_back(tile_value);
                tile_value = 0;
                tens = true;
            }
        }
        level_layout.push_back(row);
    }
    // Close the file
    f.close();
}

void Level::generate(std::string adress) // Generate the level layout from a file
{
    //std::string adress = "./data/levels/Level_";
    //int level = level_selected; 
    //adress.append(std::to_string(level));
    //adress.append(".txt");
    loadFile(adress);
	

};

int Level::getTile(int x, int y)
{
	return level_layout[y][x];
};
int Level::getWidth()
{
	if (level_layout.size() > 0)
	{
		return level_layout[0].size();
	}
	else
	{
		return 0;
	}
};
int Level::getHeight()
{
	return level_layout.size();
}
std::vector<std::vector<int>>& Level::getDesign()
{
    return level_layout;
}