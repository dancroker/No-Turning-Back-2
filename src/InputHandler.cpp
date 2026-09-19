#include "InputHandler.hpp"

InputHandler::InputHandler()
{

}

InputHandler::~InputHandler()
{

}

void InputHandler::addCharacterAction(CharacterAction action)
{
	if (std::count(active_character_actions.begin(), active_character_actions.end(), action) == 0)
	{
		active_character_actions.push_back(action);
	}
}

void InputHandler::removeCharacterAction(CharacterAction action)
{
	if (std::count(active_character_actions.begin(), active_character_actions.end(), action) > 0)
	{
		active_character_actions.erase(std::remove(active_character_actions.begin(), active_character_actions.end(), action), active_character_actions.end());
	}
}

bool InputHandler::checkCharacterAction(CharacterAction action)
{
	return std::count(active_character_actions.begin(), active_character_actions.end(), action) > 0;
}

void InputHandler::handleKeyPressed(const sf::Event::KeyPressed& keyPressed)
{
	switch(keyPressed.scancode)
	{
	case sf::Keyboard::Scancode::A:
		addCharacterAction(CharacterAction::MoveLeft);
		break;
	case sf::Keyboard::Scancode::D:
		addCharacterAction(CharacterAction::MoveRight);
		break;
	case sf::Keyboard::Scancode::W:
		addCharacterAction(CharacterAction::Jump);
		break;
	default:
		break;
	}
}

void InputHandler::handleKeyReleased(const sf::Event::KeyReleased& keyReleased)
{
	switch (keyReleased.scancode)
	{
	case sf::Keyboard::Scancode::A:
		removeCharacterAction(CharacterAction::MoveLeft);
		break;
	case sf::Keyboard::Scancode::D:
		removeCharacterAction(CharacterAction::MoveRight);
		break;
	case sf::Keyboard::Scancode::W:
		removeCharacterAction(CharacterAction::Jump);
		break;
	default:
		break;
	}
}

void InputHandler::handleMouseButtonPressed(const bool& mouseButtonPressed)
{

}

void InputHandler::handleMouseButtonReleased(const bool& mouseButtonReleased)
{

}

std::vector<CharacterAction> InputHandler::getActiveCharacterActions() const
{
	return active_character_actions;
}
