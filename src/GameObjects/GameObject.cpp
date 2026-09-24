#include <iostream>

#include "GameObject.hpp"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::init()
{
}

void GameObject::update()
{
}

void GameObject::syncSpriteWithHitbox()
{
	sprite->setPosition(sf::Vector2f{hitbox->getPosition().x + sprite_offset.x, hitbox->getPosition().y + sprite_offset.y});
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

