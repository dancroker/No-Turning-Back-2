#pragma once
#include "MenuCreator.h"
#include "../InputHandler.hpp"
#include <iostream>
class MainMenuScreen : public MenuCreator
{
public:
MainMenuScreen();
~MainMenuScreen();

void render(sf::RenderWindow& window);
void init();
void update();
int keyPressed(sf::Event event, sf::RenderWindow& window, InputHandler& input_handler);
void KeyReleased(sf::Event event);

void setMenuSelection(int selection);
int getMenuSelection();



private:

	int MenuSelection = 0;
	sf::Text Title_text;
	sf::Text Play_option;
	sf::Text Quit_option;
	sf::Font font;


	sf::Texture background_main_menu_texture;
	sf::Sprite background_main_menu_sprite;




};
