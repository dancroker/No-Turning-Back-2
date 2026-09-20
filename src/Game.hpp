#pragma once

#include <SFML/Graphics.hpp>

#include "Map/GameMap.hpp"

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	bool init();
	void update();
	void render();

private:
	sf::RenderWindow& window;

	sf::Font font_IBM_VGA_8x16{ "./data/fonts/MxPlus_IBM_VGA_8x16.ttf" };
	sf::Text text_hello_world{ font_IBM_VGA_8x16 };

	GameMap map;
};