#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "../enums/CharacterAction.hpp"


class GameObject
{
public:
	GameObject();
	GameObject(GameObject&&) noexcept = default;
	GameObject& operator=(GameObject&&) noexcept = default;
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	~GameObject();
	
	virtual void init();
	virtual void update();

	void syncSpriteWithHitbox();

	sf::RectangleShape& getHitbox() const;
	sf::Sprite& getSprite() const;
	void setTexture(std::string text_path) { texture.loadFromFile(text_path); };
	sf::Vector2f getVelocity() const; 
	void setVelocity(const sf::Vector2f& new_velocity);

protected:
	sf::Texture texture{ "./data/images/sfml-icon-small.png" };
	std::unique_ptr<sf::Sprite> sprite{ std::make_unique<sf::Sprite>(texture) };
	std::unique_ptr<sf::RectangleShape> hitbox{ std::make_unique<sf::RectangleShape>(sf::Vector2f{ 0, 0 }) };

	sf::Vector2f velocity{ 0.f, 0.f };
	sf::Vector2f sprite_offset{ 0.f, 0.f };
	float hitbox_bottom{ hitbox->getPosition().y + hitbox->getGlobalBounds().size.y };
	
};