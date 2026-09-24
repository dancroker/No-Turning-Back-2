#include "PlayerCharacter.hpp"


void PlayerCharacter::update()
{
	hitbox->setPosition(sf::Vector2f{ hitbox->getPosition().x + velocity.x, hitbox->getPosition().y + velocity.y });

	velocity.x = (velocity.x >= -0.1 && velocity.x <= 0.1) ? 0 : velocity.x / 2;
}

void PlayerCharacter::moveLeft()
{
	if (velocity.x > -speed)
		velocity.x += -speed / 2;
}

void PlayerCharacter::moveRight()
{
	if (velocity.x < speed)
		velocity.x += speed / 2;
	
}

void PlayerCharacter::jump()
{
	if (grounded)
	{
		grounded = false;
		velocity.y = -jump_power;
		sound.loadPlaySound("data/jump.wav");

	}
}

bool PlayerCharacter::getGrounded() const
{
	return grounded;
}

void PlayerCharacter::setGrounded(bool new_grounded)
{
	grounded = new_grounded;
}

float PlayerCharacter::getSpeed() const
{
  return speed;
}

void PlayerCharacter::setSpeed(float new_speed)
{
	speed = new_speed;
}

float PlayerCharacter::getJumpPower() const
{
  return jump_power;
}

void PlayerCharacter::setJumpPower(float new_jump_power)
{
	jump_power = new_jump_power;
}
