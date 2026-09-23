#include "MainMenuScreen.h"

#include "../InputHandler.hpp"

MainMenuScreen::MainMenuScreen()
{
}

void MainMenuScreen::init()
{
	Title_text = TextCreator(0, "Game Title", 50, sf::Color::White, sf::Vector2f(100.f, 50.f));
	Play_option = TextCreator(0, "Play", 30, sf::Color::White, sf::Vector2f(100.f, 150.f));
	Quit_option = TextCreator(0, "Quit", 30, sf::Color::White, sf::Vector2f(100.f, 200.f));

	if (!background_main_menu_texture.loadFromFile("data/images/background_main_menu.png"))
	{
		std::cout << "Error loading background texture" << std::endl;
	}
	background_main_menu_sprite.setTexture(background_main_menu_texture);
}

void MainMenuScreen::update()
{
}

void MainMenuScreen::KeyPressed(sf::Event event, sf::RenderWindow& window, InputHandler& input_handler)
{
	if (input_handler.checkKeysPressed(sf::Keyboard::Scancode::W) || input_handler.checkKeysPressed(sf::Keyboard::Scancode::S))
	{
        Play_selected = !Play_selected;
        if (Play_selected)
        {
            Play_option.setString("< Play >");
            Play_option.setFillColor(sf::Color::Green);
            Quit_option.setFillColor(sf::Color::Black);
            Quit_option.setString("Quit");
        }
        else
        {
            Quit_option.setString("< Quit >");
            Play_option.setFillColor(sf::Color::Black);
            Play_option.setString("Play");
            Quit_option.setFillColor(sf::Color::Green);
        }
	
	}
    if (!Play_selected && input_handler.checkKeysPressed(sf::Keyboard::Scancode::Enter))
    {
        window.close();
    }

    if (input_handler.checkKeysPressed(sf::Keyboard::Scancode::Enter))
    {

    }


    return;
}

 

