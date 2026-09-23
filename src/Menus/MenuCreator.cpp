#include "MenuCreator.h"

MenuCreator::MenuCreator()
{
	if (!font.loadFromFile("..data/fonts/MxPlus_IBM_VGA_8x16.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
}

MenuCreator::~MenuCreator()
{

}

sf::Text MenuCreator::TextCreator(int Font, sf::String text_include, int size, sf::Color text_colour, sf::Vector2 location)
{
	sf::Text text;
	text.setFont(font);
	text.setString(text_include);
	text.setCharacterSize(size);
	text.setFillColor(text_colour);
	text.setPosition(location);

	return text;
}

