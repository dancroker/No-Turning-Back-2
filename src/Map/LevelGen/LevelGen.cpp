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
		hidden_map.clear();
		std::cout << "MAP!";
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
	
}
void LevelGen::generateHiddenLevels(std::string level_name)
{
	std::vector<std::filesystem::path> files;
	for (std::filesystem::directory_entry file : std::filesystem::directory_iterator(middle_hidden_level))
	{
		//extention() = just the file type
		if (file.path().extension() == ".txt")
		{
			files.push_back(file.path());

		}
	}
	for (int i = 0; i < files.size(); ++i)
	{
		if (files[i].stem().string() == level_name)
		{
			Level level;
			level.generate(files[i].string());
			hidden_map.push_back(level);
			return;
		}
	}
		Level level;
		level.generate("data/levels/MiddleHidden/EMPTY.txt");
		hidden_map.push_back(level);
}

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
void LevelGen::printHiddenMap()
{
	for (Level& level : hidden_map)
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
	std::cout << "Hidden map size: " << hidden_map.size() << std::endl;
}
std::vector<std::vector<int>>& LevelGen::getLevelLayout(int section, bool hidden)
{
	if (hidden)
	{
		return hidden_map[section].getDesign();
	}
	return map[section].getDesign();
}

int LevelGen::amountOfLevels()
{
	return map.size();
}

void LevelGen::unlockHiddenLevelSection(int section)
{
	if (hidden_map.size() > 0)
	{
		std::cout << "Unlocking hidden level section: " << section << std::endl;
		hidden_map[section].clearLevel(section);
	}
	else
	{
		std::cerr << "Error: No hidden levels to unlock." << std::endl;
	}
}

std::vector<Level>& LevelGen::getMap()
{
	return map;
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
		generateHiddenLevels(files[level_selected].stem().string());
	}
}	