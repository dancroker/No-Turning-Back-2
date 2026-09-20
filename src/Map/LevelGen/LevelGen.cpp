#include "LevelGen.hpp"

LevelGen::LevelGen()
{
	// Constructor implementation
};
LevelGen::~LevelGen()
{
	// Destructor implementation
};
void LevelGen::generateLevels(int number_of_levels)
{
	int level_file_count = 0;
	//directory_entry = data type for a file found in directory / folders
	//directory_iterator = iterator that goes through each file in the directory / folder 
	for(std::filesystem::directory_entry file : std::filesystem::directory_iterator("data/levels"))
	{
		//extention() = just the file type
		if(file.path().extension() == ".txt")
		{
			level_file_count++;
		}
	}
	if (number_of_levels <= 0)
	{
		std::cerr << "Error: number_of_levels must be greater than 0." << std::endl;
		return;
	}
	if (map.size() > 0)
	{
		map.clear();
	}
	for (int i = 0; i < number_of_levels; ++i)
	{
		Level level;
		int level_selected = (rand() % level_file_count)+1;
		level.generate(level_selected);
		map.push_back(level);
	}
};

void LevelGen::printMap()
{
	for (Level& level : map)
	{
		for (int y = 0; y < level.getHeight(); ++y) 
		{
			for (int x = 0; x < level.getWidth(); ++x)
			{
				std::cout << level.getTile(x, y) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}
std::vector<std::vector<int>>& LevelGen::getLevelLayout(int section)
{
	return map[section].getDesign();
}

int LevelGen::amountOfLevels()
{
	return map.size();
}
