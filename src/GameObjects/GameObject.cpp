#include <iostream>

#include "GameObject.hpp"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::update()
{
	
}

sf::RectangleShape& GameObject::getHitbox() const
{
	return *hitbox;
}

sf::Sprite& GameObject::getSprite() const
{
	return *sprite;
}

sf::Vector2f GameObject::getVelocity() const
{
	return velocity;
}

void GameObject::setVelocity(const sf::Vector2f& new_velocity)
{
	velocity = new_velocity;
}

