#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../enums/CharacterAction.hpp"


class GameObject
{
public:
	GameObject();
	~GameObject();
	
	virtual void update();

	sf::RectangleShape& getHitbox() const;
	sf::Sprite& getSprite() const;

	sf::Vector2f getVelocity() const;
	void setVelocity(const sf::Vector2f& new_velocity);

protected:
	sf::Texture texture{ sf::Vector2u(1, 1) };
	std::unique_ptr<sf::Sprite> sprite{ std::make_unique<sf::Sprite>(texture) };
	std::unique_ptr<sf::RectangleShape> hitbox{ std::make_unique<sf::RectangleShape>(sf::Vector2f{ 0, 0 }) };

	sf::Vector2f velocity{ 0.f, 0.f };
	float hitbox_bottom{ hitbox->getPosition().y + hitbox->getGlobalBounds().size.y };
	
};