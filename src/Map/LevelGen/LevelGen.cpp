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
	if (map.size() > 0)
	{
		map.clear();
	}
	if (number_of_levels < 3)
	{
		std::cerr << "Error: number_of_levels must be at least 3." << std::endl;
		return;
	}
	else
	{
		generateSectionOfLevel(1, end_level);
		generateSectionOfLevel(number_of_levels - 2, middle_level);
		generateSectionOfLevel(1, start_level);
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

void LevelGen::generateSectionOfLevel(int number_of_levels, std::filesystem::path file_path)
{
	std::vector<std::filesystem::path> files;
	//directory_entry = data type for a file found in directory / folders
	//directory_iterator = iterator that goes through each file in the directory / folder 
	for (std::filesystem::directory_entry file : std::filesystem::directory_iterator(file_path))
	{
		//extention() = just the file type
		if (file.path().extension() == ".txt")
		{
			files.push_back(file.path());

		}
	}
	if (number_of_levels <= 0)
	{
		std::cerr << "Error: number_of_levels must be greater than 0." << std::endl;
		return;
	}
	for (int i = 0; i < number_of_levels; ++i)
	{
		Level level;
		int level_selected = (rand() % files.size());
		level.generate(files[level_selected].string());
		map.push_back(level);
	}
}	