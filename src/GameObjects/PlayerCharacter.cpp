#include "PlayerCharacter.hpp"

void PlayerCharacter::init()
{
	player_camera->setSize(sf::Vector2f{ 1080, 720 });
}

void PlayerCharacter::update(float& gravity, std::vector<Level>& map, float tile_size)
{
	updateCollision(map, tile_size);
	hitbox->setPosition(sf::Vector2f{ hitbox->getPosition().x + velocity.x, hitbox->getPosition().y + velocity.y });

	if (col_velocity.x != 0 || col_velocity.y != 0)
	{
		do
		{
			updateCollision(map, tile_size);
			if (col_velocity.x != 0) 
			{
				getHitbox().move({ col_velocity.x, 0 });
			}
		} while (col_velocity.x != 0);
		do
		{
			updateCollision(map, tile_size);
			if (col_velocity.y != 0)
			{
				getHitbox().move({0, col_velocity.y});
			}
		} while (col_velocity.y != 0);
	}
	std::cout << velocity.y << std::endl;

	//hitbox->setPosition(sf::Vector2f{ hitbox->getPosition().x + velocity.x, hitbox->getPosition().y + velocity.y });
	syncSpriteWithHitbox();
	centerCamera();

	applyGravity(gravity);
	velocity.x = (velocity.x >= -0.1 && velocity.x <= 0.1) ? 0 : velocity.x / 2;
}

void PlayerCharacter::updateCollision(std::vector<Level>& map, float tile_size)
{
	bool touching_tile{ false };

	///
	col_velocity = { 0.f,0.f };
	// 

	int level_count = 0;

	for (Level& level : map)
	{
		for (int row_num{ 0 }; row_num < level.getHeight(); row_num++)
		{
			for (int col_num{ 0 }; col_num < level.getWidth(); col_num++)
			{
				float tile_y = (row_num * tile_size) + (level.getHeight() * tile_size) * level_count;
				float tile_x = (col_num * tile_size);
				float x = getHitbox().getPosition().x;
				float y = getHitbox().getPosition().y;
				float width = getHitbox().getGlobalBounds().size.x;
				float height = getHitbox().getGlobalBounds().size.y;
				// tile x - x os of tile on screen
				// x * size of tile + account for levels beung ontop of each other (add tile size * 
				///tile y - y tile pos on screen
				if (level.getTile(col_num, row_num) == 1) // 1 == tile
				{
					if (x < tile_x + tile_size && x + width > tile_x && y < tile_y + tile_size && y + height > tile_y)
					{
						if (x < tile_x + tile_size / 2 && x + width > tile_x)
						{
							//collison_move.x = -1;
							col_velocity.x = -1;
						}
						else
						{
							//collison_move.x = 1;
							col_velocity.x = 1;
						}
						if (y < tile_y + tile_size / 2 && y + height > tile_y)
						{
							//collison_move.y = -1;
							col_velocity.y = -1;
							touching_tile = true;
						}
						else
						{
							//collison_move.y = 1;
							col_velocity.y = 1;
						}
						std::cout << col_velocity.x << "," << col_velocity.y << std::endl;
					}
				}
			}
		}
		level_count++;
	}

	///

	if (touching_tile)
	{
		grounded = true;
	}
	else
	{
		grounded = false;
	}
}

void PlayerCharacter::centerCamera()
{
	//player_camera->setCenter(sf::Vector2f{ hitbox->getPosition().x + hitbox->getGlobalBounds().size.x / 2, hitbox->getPosition().y + hitbox->getGlobalBounds().size.y / 2 });
	player_camera->setCenter(sf::Vector2f{ player_camera->getCenter().x , hitbox->getPosition().y + hitbox->getGlobalBounds().size.y / 2});
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
	//if (grounded)
	//{
		velocity.y = -jump_power;
		//sound.loadPlaySound("data/jump.wav"); // Loading causes too much lag

	//}
}

void PlayerCharacter::applyGravity(float& gravity)
{
	if (!grounded)
	{
		velocity.y += (velocity.y > 10 || velocity.y < -10) ? 0 : gravity / 10;
	}
	//else if (grounded)
	//{
	//	velocity.y = 0;
	//}
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
