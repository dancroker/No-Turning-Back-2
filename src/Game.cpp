#include <iostream>

#include "Game.hpp"

#include "enums/GameState.hpp"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
	srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
	text_hello_world.setString("Press ENTER to start");

	player.initialiseSprite(player_texture, "./data/images/Bg_3.png");
	player.getSprite()->setPosition(sf::Vector2f(0.0f, 500.0f));
	player.getSprite()->setScale(sf::Vector2f(0.5f, 0.5f));
	player.setSpeed(200);
	jumpHeight = 200;
    jumpStartY = player.getSprite()->getPosition().y;
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
		// TODO: physics, movement, collision detection.
		break;
	case GameState::Paused:
		break;
	case GameState::GameOver:
		break;
	default:
		break;
	}


	// arrows
	if (input_handler->checkCharacterAction(CharacterAction::MoveLeft) && input_handler->checkCharacterAction(CharacterAction::Jump))
	{
		std::cout << "\\";
	}
	else if (input_handler->checkCharacterAction(CharacterAction::MoveRight) && input_handler->checkCharacterAction(CharacterAction::Jump))
	{
		std::cout << "/";

	}
	else if (input_handler->checkCharacterAction(CharacterAction::Jump))
	{
		if(onGround){
			jumpStartY = player.getSprite()->getPosition().y; 
        	onGround = false;
        	velocity.y = -jumpSpeed;
		}
		std::cout << "^";
	}
	else if (input_handler->checkCharacterAction(CharacterAction::MoveLeft))
	{
		std::cout << "<";
	}
	else if (input_handler->checkCharacterAction(CharacterAction::MoveRight))
	{
		player.setDirection(Vector2(1.0f, 0.0f));
		player.getSprite()->move(sf::Vector2f(player.getDirection().x * player.getSpeed() * dt, 0));
		std::cout << ">";
	}
	else
	{
		std::cout << ".";
	}
	if (input_handler->checkKeysPressed(sf::Keyboard::Scancode::Enter))
	{
          std::cout << "[ENTER]";
	}
	std::cout << std::endl;
	//allowing to jump
	velocity.y += gravity * dt;
    player.getSprite()->move(sf::Vector2f(0, velocity.y));
    if(player.getSprite()->getPosition().y < jumpStartY - jumpHeight && velocity.y < 0 ) {
        velocity.y = 0;   
    }

    const sf::FloatRect spriteBounds = player.getSprite()->getGlobalBounds();
    if(player.getSprite()->getPosition().y + spriteBounds.size.y >= groundHeight){
        player.getSprite()->setPosition(sf::Vector2f(player.getSprite()->getPosition().x, groundHeight - spriteBounds.size.y));
        velocity.y = 0;
        onGround = true;
      }  
}

void Game::render()
{
	window.clear(sf::Color{ 100, 149, 237, 255 });

	switch (current_game_state)
	{
	case GameState::MainMenu:
			window.draw(text_hello_world);
			
		break;
	case GameState::Playing:
			if (player.getSprite())
			{
				window.draw(*player.getSprite());
			}
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
