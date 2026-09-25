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

void PlayerCharacter::update(float& gravity, std::vector<Level>& map, float tile_size)
{
	
	syncSpriteWithHitbox();
	centerCamera();
	//hitbox->setPosition(sf::Vector2f{ hitbox->getPosition().x + velocity.x, hitbox->getPosition().y + velocity.y });


	updateCollision(map, tile_size, true);

	if (col_velocity.x == 0.f)
	{
		getHitbox().move({ velocity.x, 0.f });
		std::cout << velocity.x << std::endl;
	}
	else
	{
		do
		{
			getHitbox().move({ col_velocity.x, 0.f });
			syncSpriteWithHitbox();
			updateCollision(map, tile_size, true);
		} while (col_velocity.x != 0);
	}

	updateCollision(map, tile_size, false);

	if (col_velocity.y == 0.f) // 
	{
		getHitbox().move({ 0.f, velocity.y });
		grounded = false;
	}
	else
	{
		do
		{
			getHitbox().move({ 0.f, col_velocity.y });
			syncSpriteWithHitbox();
			grounded = true;
			updateCollision(map, tile_size, false);
		} while (col_velocity.y != 0);
	}

	applyGravity(gravity);

	// simple horizontal friction
	velocity.x = (std::abs(velocity.x) < 0.1f) ? 0.f : velocity.x / 2.f;

}

void PlayerCharacter::updateCollision(std::vector<Level>& map, float tile_size, bool check_top)
{
	col_velocity = { 0.f,0.f };

	int level_count = 0;

	for (Level& level : map)
	{
		for (int row_num{ 0 }; row_num < level.getHeight(); row_num++)
		{
			for (int col_num{ 0 }; col_num < level.getWidth(); col_num++)
			{
				float tile_y = (row_num * tile_size) + (level.getHeight() * tile_size) * level_count;
				float tile_x = (col_num * tile_size);
				float x = getSprite().getPosition().x;
				float y = getSprite().getPosition().y;
				float width = getSprite().getGlobalBounds().size.x;
				float height = getSprite().getGlobalBounds().size.y / 2;
				if (!check_top)
				{
					 x = getSprite().getPosition().x + getSprite().getGlobalBounds().size.x / 4;
					 y = getSprite().getPosition().y-3;
					 width = getSprite().getGlobalBounds().size.x / 2;
					 height = getSprite().getGlobalBounds().size.y;
				}
				
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
}

void PlayerCharacter::centerCamera()
{
	//player_camera->setCenter(sf::Vector2f{ hitbox->getPosition().x + hitbox->getGlobalBounds().size.x / 2, hitbox->getPosition().y + hitbox->getGlobalBounds().size.y / 2 });
	player_camera->setCenter(sf::Vector2f{ 250 , hitbox->getPosition().y + hitbox->getGlobalBounds().size.y / 2});
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
		//getHitbox().move({ 0.f,1.f });
		//sound.loadPlaySound("data/jump.wav"); // Loading causes too much lag

		printf("jumping\n");
		velocity.y = -jump_power / 3;
		grounded = false;
	} else {
	
	}
}

void PlayerCharacter::applyGravity(float& gravity)
{
	if (!grounded)
	{	
		printf("not grounded\n");
		velocity.y += 1;
	}
	else {
		velocity.y = 0;
		printf("grounded\n");
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

void PlayerCharacter::MOVEUPPP()
{
	getHitbox().move({ 0.f,-1.f });
}
