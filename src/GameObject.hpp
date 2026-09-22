#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

	//For player
	bool initialiseSprite(sf::Texture& texture, std::string filename);
  	sf::Sprite* getSprite();

private:
	sf::Sprite* sprite = nullptr;
};