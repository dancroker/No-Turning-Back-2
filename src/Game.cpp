#include <iostream>

#include "Game.hpp"

#include "enums/GameState.hpp"

Game::Game(sf::RenderWindow& game_window) : window(game_window), 
opening_animation_1("data/Frame1.png",1000,1000,15,0), opening_animation_2("data/Frame2.png", 1000, 1000, 15, 0)
, opening_animation_3("data/Frame3.png", 1000, 1000, 15, 0), opening_animation_4("data/Frame4.png", 1000, 1000, 9, 0)
{
	srand(time(NULL));
	float scale_factor = 0.7f;
	opening_animation_1.setScale(scale_factor, scale_factor);
	opening_animation_2.setScale(scale_factor, scale_factor);
	opening_animation_3.setScale(scale_factor, scale_factor);
	opening_animation_4.setScale(scale_factor, scale_factor);
}

Game::~Game() {}

bool Game::init()
{
	text_hello_world.setString("Hello, World!");
	map.generate(4); 

	text_enter.setString("[Press ENTER to start]");
	text_enter.setPosition(sf::Vector2f{ 0.f, 100.f });

	player.getHitbox().setFillColor(sf::Color::Magenta);
	player.getHitbox().setSize(sf::Vector2f{ 50.f, 50.f });
	player.setSpeed(20.f);

	return true;
}

void Game::update(float dt)
{
	switch (current_game_state)
	{
	case GameState::MainMenu:
		if (input_handler->checkKeysPressed(sf::Keyboard::Scancode::Enter))
			current_game_state = GameState::Playing;
		break;
	case GameState::Playing:
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
					break;
				case CharacterAction::Interact:
					break;
				default:
					break;
				}
			}
		}
		player.update();
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

	switch (current_game_state)
	{
	case GameState::MainMenu:
		window.draw(text_hello_world);
		window.draw(text_enter);

		playOpeningAnimation();
		
		break;
	case GameState::Playing:
		window.draw(sprite_sfml_logo);
		window.draw(player.getHitbox());
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
