#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "enums/GameState.hpp"
#include "InputHandler.hpp"
#include "GameObject.hpp"


class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	bool init();
	void update(float dt);
	void render();

	InputHandler& getInputHandler() const;

	GameState getCurrentGameState() const;
	void setCurrentGameState(GameState newGameState);
	

private:
	sf::RenderWindow& window;

	std::unique_ptr<InputHandler> input_handler{ std::make_unique<InputHandler>() };

	GameState current_game_state{ GameState::MainMenu };

	sf::Font font_IBM_VGA_8x16{ "./data/fonts/MxPlus_IBM_VGA_8x16.ttf" };
	sf::Text text_hello_world{ font_IBM_VGA_8x16 };
	sf::Text text_enter{ font_IBM_VGA_8x16 };

	//Player
	GameObject player;
	sf::Texture player_texture;
	float jumpHeight;
	float jumpStartY;
	bool onGround = true;
		//highest point of jump
	int player_jumpy = window.getSize().y - 200;
	float jumpSpeed = 10.0f;
	float gravity   = 10;
	float groundHeight = window.getSize().y - 100;
	Vector2 velocity = { 0.0f, 0.0f };

};