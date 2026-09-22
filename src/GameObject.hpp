#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	//For player
	bool initialiseSprite(sf::Texture& texture, std::string filename);
  	sf::Sprite* getSprite();
	int speed;
	Vector2 getDirection();
	void setDirection(Vector2 dir);
	void setSpeed(int spee);
	int getSpeed(){return speed;}
	Vector2 direction = {0, 1};

private:
	sf::Sprite* sprite = nullptr;
};