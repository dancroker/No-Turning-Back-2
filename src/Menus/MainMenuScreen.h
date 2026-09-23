#pragma once
#include "MenuCreator.h"
class MainMenuScreen : public MenuCreator
{
public:
MainMenuScreen();
~MainMenuScreen();

void render(sf::RenderWindow& window);
void init();
void update();
void KeyPressed(sf::Event event, sf::RenderWindow& window, InputHandler& input_handler);
void KeyReleased(sf::Event event);

private:

	sf::Text Title_text;
	sf::Text Play_option;
	sf::Text Quit_option;

	sf::Texture background_main_menu_texture;
	sf::Sprite background_main_menu_sprite;

	int Play_selected;


};
