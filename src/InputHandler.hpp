#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

#include "enums/CharacterAction.hpp"
#include "enums/GameState.hpp"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void addCharacterAction(CharacterAction action);
	void removeCharacterAction(CharacterAction action);
	bool checkCharacterAction(CharacterAction action);

	void addKeysPressed(sf::Keyboard::Scancode key);
	void removeKeysPressed(sf::Keyboard::Scancode key);
	bool checkKeysPressed(sf::Keyboard::Scancode key);

	void handleKeyPressed(const sf::Event::KeyPressed& keyPressed);
	void handleKeyReleased(const sf::Event::KeyReleased& keyReleased);
	void handleMouseButtonPressed(const bool& mouseButtonPressed);
	void handleMouseButtonReleased(const bool& mouseButtonReleased);

	std::vector<CharacterAction> getActiveCharacterActions() const;
	
private:

	std::vector<CharacterAction> active_character_actions;
	std::vector<sf::Keyboard::Scancode> keys_pressed;

};