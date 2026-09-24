#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MenuCreator
{
public:
	MenuCreator();
	~MenuCreator();

	sf::Text TextCreator(int Font, sf::String text_include, int size, sf::Color text_colour, sf::Vector2f location);

private:
	sf::Font font;
};
