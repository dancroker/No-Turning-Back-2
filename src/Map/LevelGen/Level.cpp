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
    else 
    {
		std::cout << "File opened successfully: " << adress << std::endl;
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
void Level::clearLevel(int section)
{
	for (int y = 0; y < level_layout.size(); ++y)
	{
		for (int x = 0; x < level_layout[y].size(); ++x)
		{
			level_layout[y][x] = 0;
		}
	}
}
std::vector<std::vector<int>>& Level::getDesign()
{
    return level_layout;
}

sf::Vector2i Level::getPlayerSpawn()
{
    for (int y = 0; y < level_layout.size(); ++y)
    {
        for (int x = 0; x < level_layout[y].size(); ++x)
        {
            if (level_layout[y][x] == 3) // Assuming 3 represents the player spawn tile
            {
                return sf::Vector2i(x, y);
            }
        }
    }
    return sf::Vector2i(-1, -1); // Return a default position if no spawn point is found
}
