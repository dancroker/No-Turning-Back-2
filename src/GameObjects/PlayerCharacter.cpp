#include "PlayerCharacter.hpp"

PlayerCharacter::PlayerCharacter(): jump_sfx_sound(jump_sfx_sound_buffer)
{
	jump_sfx_sound_buffer.loadFromFile("data/jump.wav");
	jump_sfx_sound.setBuffer(jump_sfx_sound_buffer);
	// jump_sfx_sound.play(); - In Jump function!
}

PlayerCharacter::~PlayerCharacter()
{}

void PlayerCharacter::init()
{
	player_camera->setSize(sf::Vector2f{ 1080, 720 });

}

void PlayerCharacter::update()
{
	hitbox->setPosition(sf::Vector2f{ hitbox->getPosition().x + velocity.x, hitbox->getPosition().y + velocity.y });
	syncSpriteWithHitbox();
	centerCamera();

	velocity.x = (velocity.x >= -0.1 && velocity.x <= 0.1) ? 0 : velocity.x / 2;
}

void PlayerCharacter::centerCamera()
{
	player_camera->setCenter(sf::Vector2f{ hitbox->getPosition().x + hitbox->getGlobalBounds().size.x / 2, hitbox->getPosition().y + hitbox->getGlobalBounds().size.y / 2 });
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
	}
}

sf::View& PlayerCharacter::getPlayerCamera() const
{
	return *player_camera;
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
