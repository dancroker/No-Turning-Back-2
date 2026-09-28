#pragma once
#include "MenuCreator.h"
#include "../InputHandler.hpp"
#include <iostream>
#include "../GameObjects/GameObject.hpp"
class SelectLevelMenu : public MenuCreator
{
public:
	SelectLevelMenu();
	~SelectLevelMenu();

	void render(sf::RenderWindow& window);
	void init();
	void update();
	int keyPressed(int direction); // 0 = up, 1 = down, 2 = left, 3 = right, 4 = enter, 5 = escape
	void KeyReleased(sf::Event event);
	void increaseLevelsUnlocked() { LevelsUnlocked += 1; };
	void setMenuSelection(int selection);
	int getMenuSelection();



private:

	int MenuSelection = 0;
	int LevelsUnlocked = 1;
	sf::Text Title_text;
	sf::Text Level_Number;
	sf::Text Quit_option;
	sf::Font font;
	sf::Texture background_main_menu_texture;
	sf::Sprite background_main_menu_sprite;

	GameObject lock;




};
