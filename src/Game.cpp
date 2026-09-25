#include <iostream>

#include "Game.hpp"

#include "enums/GameState.hpp"

#include "Menus/MainMenuScreen.h"


Game::Game(sf::RenderWindow& game_window) : window(game_window), 
opening_animation_1("data/Frame1.png",1000,1000,15,0), opening_animation_2("data/Frame2.png", 1000, 1000, 15, 0)
, opening_animation_3("data/Frame3.png", 1000, 1000, 15, 0), opening_animation_4("data/Frame4.png", 1000, 1000, 9, 0), 
menu_music_sound(menu_music_sound_buffer), game_music_sound(game_music_sound_buffer)
{
	srand(time(NULL));
	float scale_factor = 0.7f;
	opening_animation_1.setScale(scale_factor, scale_factor);
	opening_animation_2.setScale(scale_factor, scale_factor);
	opening_animation_3.setScale(scale_factor, scale_factor);
	opening_animation_4.setScale(scale_factor, scale_factor);
	menu_music_sound_buffer.loadFromFile("data/music/menu_music.wav");
	menu_music_sound.setBuffer(menu_music_sound_buffer);
	game_music_sound_buffer.loadFromFile("data/music/game_music.wav");
	game_music_sound.setBuffer(game_music_sound_buffer);
}

Game::~Game() {}

bool Game::init()
{
	//music.loadPlayMusic(); // Loading the music goes here instead of in the render loop.

	text_hello_world.setString("Hello, World!");
	map.generate(3);

	text_enter.setString("[Press ENTER to start]");
	text_enter.setPosition(sf::Vector2f{ 0.f, 100.f });

	player.init();
	player.getSprite().setTexture(texture_player);
	player.getHitbox().setFillColor(sf::Color::Magenta);
	player.getHitbox().setSize(sf::Vector2f{ 10.f, 10.f });
	player.getSprite().setScale(sf::Vector2f{ 0.234f, 0.234f });
	player.setSpeed(20.f);
	
	main_menu_screen.init();




	return true;
}

void Game::update(float dt)
{
	switch (current_game_state)
	{
	case GameState::MainMenu:

		if (menu_music_sound.getStatus() == sf::SoundSource::Status::Stopped)
		{
			menu_music_sound.play();
			game_music_sound.stop();
		}

		if (input_handler->checkKeysPressed(sf::Keyboard::Scancode::Enter))
		{
			current_game_state = GameState::IntroCutscene;
		}

		if (!s_key_pressed && input_handler->checkKeysPressed(sf::Keyboard::Scancode::S))
		{
			main_menu_screen.setMenuSelection(main_menu_screen.getMenuSelection() + 1);
			if (main_menu_screen.getMenuSelection() > 1)
				main_menu_screen.setMenuSelection(1);

			s_key_pressed = true;

			std::cout << "MenuSelection: " << main_menu_screen.getMenuSelection() << std::endl;
		}

		if (!input_handler->checkKeysPressed(sf::Keyboard::Scancode::S))
			s_key_pressed = false;

		if (!w_key_pressed && input_handler->checkKeysPressed(sf::Keyboard::Scancode::W))
		{
			std::cout << "W pressed" << std::endl;

			 main_menu_screen.setMenuSelection(main_menu_screen.getMenuSelection() - 1);
			if (main_menu_screen.getMenuSelection() < 0)
				main_menu_screen.setMenuSelection(0);

			w_key_pressed = true;
			std::cout << "MenuSelection: " << main_menu_screen.getMenuSelection() << std::endl;
		}

		if (!input_handler->checkKeysPressed(sf::Keyboard::Scancode::W))
			w_key_pressed = false;

		if (main_menu_screen.getMenuSelection() == 1 && input_handler->checkKeysPressed(sf::Keyboard::Scancode::Enter))
		{
			window.close();
		}


		break;
	case GameState::Playing:
		map.update(); //--------------------------------------------------------------

		if (game_music_sound.getStatus() == sf::SoundSource::Status::Stopped)
		{
			menu_music_sound.stop();
			game_music_sound.play();
		}

		if (!input_handler->getActiveCharacterActions().empty())
		{
			for (CharacterAction action : input_handler->getActiveCharacterActions())
			{
				switch (action)
				{
				case CharacterAction::Idle:
					break;
				case CharacterAction::MoveLeft:
					player.moveLeft();
					break;
				case CharacterAction::MoveRight:
					player.moveRight();
					break;
				case CharacterAction::Jump:
					player.jump();
					break;
				case CharacterAction::Interact:
					player.MOVEUPPP();
					break;
				default:
					break;
				}
			}
		}
		player.update(gravity, map.getLevelGen().getMap(), map.getTileSize());
		break;
	case GameState::Paused:
		break;
	case GameState::GameOver:
		break;
	default:
		break;
	}
}

void Game::render()
{
	window.clear(sf::Color{ 100, 149, 237, 255 }); // Cornflower Blue
	window.setView(window.getDefaultView());

	switch (current_game_state)
	{
	case GameState::MainMenu:
		main_menu_screen.render(window);
		window.draw(text_hello_world);
		window.draw(text_enter);
		
		break;
	case GameState::IntroCutscene:
		if (game_music_sound.getStatus() == sf::SoundSource::Status::Playing || menu_music_sound.getStatus() == sf::SoundSource::Status::Playing)
		{
			menu_music_sound.stop();
			game_music_sound.stop();
		}
		playOpeningAnimation();
		break;
	case GameState::Playing:
		window.setView(player.getPlayerCamera());
		window.draw(sprite_sfml_logo);
		window.draw(player.getHitbox());
		window.draw(player.getSprite());
		map.draw_map(window);
		break;
	case GameState::Paused:
		break;
	case GameState::GameOver:
		break;
	default:
		break;
	}

}

int Game::keyPressed(sf::Event event, sf::RenderWindow& window, InputHandler& input_handler)
{
	switch (current_game_state)
	{
	case GameState::MainMenu:
		int menu_selection = main_menu_screen.keyPressed(event, window, input_handler);
		std::cout << "Menu Selection: " << menu_selection << std::endl;
		break;
	}
	return 0;
}

InputHandler& Game::getInputHandler() const
{
	return *input_handler;
}

GameState Game::getCurrentGameState() const
{
	return current_game_state;   
}

void Game::setCurrentGameState(GameState newGameState)
{
	current_game_state = newGameState;
}

void Game::keyReleased(sf::Event event)
{
}

void Game::playOpeningAnimation()
{
	if (opening_animation_1.play() < 1)
	{
		window.draw(opening_animation_1.getSprite());
	}
	else if (opening_animation_2.play() < 1)
	{
		window.draw(opening_animation_2.getSprite());
	}
	else if (opening_animation_3.play() < 1)
	{
		window.draw(opening_animation_3.getSprite());
	}
	else if (opening_animation_4.play() < 1)
	{
		window.draw(opening_animation_4.getSprite());
	}
	else
	{
		setCurrentGameState(GameState::Playing);
	}
}
