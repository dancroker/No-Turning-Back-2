#include "MainMenuScreen.h"

#include "../InputHandler.hpp"

MainMenuScreen::MainMenuScreen() : Title_text(font), Play_option(font), Quit_option(font), background_main_menu_sprite(background_main_menu_texture)
{
}

void MainMenuScreen::init()
{
	if (!background_main_menu_texture.loadFromFile("2026GameJam/data/images/Menu_background.png"))
	{
		std::cout << "Error loading background texture" << std::endl;
	}

	Title_text = TextCreator(0, "Game Title", 50, sf::Color::Green, sf::Vector2f(100.f, 50.f));
	Play_option = TextCreator(0, "Play", 30, sf::Color::White, sf::Vector2f(100.f, 150.f));
	Quit_option = TextCreator(0, "Quit", 30, sf::Color::White, sf::Vector2f(100.f, 200.f));

	background_main_menu_sprite.setTexture(background_main_menu_texture);

	background_main_menu_sprite.setScale(sf::Vector2f{ 0.5f, 0.5f });

}

void MainMenuScreen::update()
{
   
}
int MainMenuScreen::keyPressed(sf::Event event, sf::RenderWindow& window, InputHandler& input_handler)
{
	return 0;
}

void MainMenuScreen::render(sf::RenderWindow& window)
{
	if (MenuSelection == 0)
	{
		Play_option.setFillColor(sf::Color::Green);
		Quit_option.setFillColor(sf::Color::Black);
	}
	else
	{
		Play_option.setFillColor(sf::Color::Black);
		Quit_option.setFillColor(sf::Color::Green);
	}
	window.draw(background_main_menu_sprite);
	window.draw(Title_text);
	window.draw(Play_option);
	window.draw(Quit_option);


}

int MainMenuScreen::getMenuSelection()
{
	return MenuSelection;
}

void MainMenuScreen::setMenuSelection(int selection)
{
	MenuSelection = selection;
}



MainMenuScreen::~MainMenuScreen() 
{

};