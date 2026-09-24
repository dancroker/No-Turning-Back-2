#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "enums/GameState.hpp"
#include "InputHandler.hpp"
#include "GameObjects/GameObject.hpp"
#include "GameObjects/PlayerCharacter.hpp"
#include "GameObjects/Star.hpp"
#include "Map/GameMap.hpp"
#include "Menus/MainMenuScreen.h"
#include "AnimationManager.hpp"
#include "OwnSound.hpp"

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	bool init();
	void update(float dt);
	void render();
	int keyPressed(sf::Event event, sf::RenderWindow& window, InputHandler& input_handler);
	void keyReleased(sf::Event event);

	InputHandler& getInputHandler() const;

	GameState getCurrentGameState() const;
	void setCurrentGameState(GameState newGameState);

	void playOpeningAnimation();
	

private:
	sf::RenderWindow& window;

	std::unique_ptr<InputHandler> input_handler{ std::make_unique<InputHandler>() };

	GameState current_game_state{ GameState::MainMenu };

	sf::Font font_IBM_VGA_8x16{ "./data/fonts/MxPlus_IBM_VGA_8x16.ttf" };
	sf::Text text_hello_world{ font_IBM_VGA_8x16 };
	sf::Text text_enter{ font_IBM_VGA_8x16 };

	sf::Texture texture_sfml_icon{ "./data/images/sfml-icon-small.png" };
	sf::Texture texture_sfml_logo{ "./data/images/sfml-logo.png" };
	sf::Texture texture_player{ "./data/images/sfml-icon-small.png" };
	sf::Texture texture_star{ "./data/images/Colectable.png" };
	
	sf::Sprite sprite_sfml_logo{ texture_sfml_logo }; // placeholder reference for movement

	PlayerCharacter player{};
	Star star{};

	float gravity{ 10.f };

	GameMap map;

	AnimationManager opening_animation_1;
	AnimationManager opening_animation_2;
	AnimationManager opening_animation_3;
	AnimationManager opening_animation_4;

	OwnSound music;

	//Player
	//GameObject player;
	//float jumpHeight;
	//float jumpStartY;
	//bool onGround = true;
	//	//highest point of jump
	//int player_jumpy = window.getSize().y - 200;
	//float jumpSpeed = 10.0f;
	//float gravity   = 10;
	//float groundHeight = window.getSize().y - 100;
	//Vector2 velocity = { 0.0f, 0.0f };

	bool s_key_pressed{ false };
	bool w_key_pressed{ false };
	



	MainMenuScreen main_menu_screen;

};