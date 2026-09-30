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

void PlayerCharacter::update(float& gravity, std::vector<Level>& map, std::vector<Level>& hidden_map, float tile_size, sf::RenderWindow& window)
{
	
	syncSpriteWithHitbox();
	centerCamera();
	//hitbox->setPosition(sf::Vector2f{ hitbox->getPosition().x + velocity.x, hitbox->getPosition().y + velocity.y });

	can_move_vertically = true;
	can_move_horizontally = true;
	grounded = false;
	col_moved_up = false;

	int level_count = 0;
	for (Level& level : map)
	{
		for (int row_num{ 0 }; row_num < level.getHeight(); row_num++)
		{
			for (int col_num{ 0 }; col_num < level.getWidth(); col_num++)
			{
				float tile_y = (row_num * tile_size) + (level.getHeight() * tile_size) * level_count;
				float tile_x = (col_num * tile_size);
				sf::FloatRect box = { {tile_x,tile_y},{tile_size,tile_size} };
				if (level.getTile(col_num, row_num) == 1) {
					if (getGlobalBounds().findIntersection(box))
					{
						updateCollision(map, tile_size, box.position.x, box.position.y, 1, window);
						if (col_velocity.y != 0.f)
						{
							getHitbox().move({ 0.f, -1.0f });
							grounded = true;
							can_move_vertically = false;
							col_moved_up = true;
						}
						updateCollision(map, tile_size, box.position.x, box.position.y, 0, window);
						if (col_velocity.y != 0.f && col_moved_up == false)
						{
							getHitbox().move({ 0.f, 1.0f });
							can_move_vertically = false;
							col_moved_up = true;

						}
						updateCollision(map, tile_size, box.position.x, box.position.y, 2, window);
						if (col_velocity.x != 0.f)
						{
							getHitbox().move({ -1.0f,0.f });
							can_move_horizontally = false;
						}
						updateCollision(map, tile_size, box.position.x, box.position.y, 3, window);
						if (col_velocity.x != 0.f)
						{
							getHitbox().move({ 1.0f,0.f });
							can_move_horizontally = false;
						}

					}
				}

			}
		}
		level_count++;
	}
	col_moved_up = false;
	level_count = 0;
	for (Level& level : hidden_map)
	{
		for (int row_num{ 0 }; row_num < level.getHeight(); row_num++)
		{
			for (int col_num{ 0 }; col_num < level.getWidth(); col_num++)
			{
				float tile_y = (row_num * tile_size) + (level.getHeight() * tile_size) * level_count;
				float tile_x = (col_num * tile_size);
				sf::FloatRect box = { {tile_x,tile_y},{tile_size,tile_size} };
				if (level.getTile(col_num, row_num) == 1) {
					if (getGlobalBounds().findIntersection(box))
					{
						updateCollision(hidden_map, tile_size, box.position.x, box.position.y, 1, window);
						if (col_velocity.y != 0.f)
						{
							getHitbox().move({ 0.f, -1.0f });
							grounded = true;
							can_move_vertically = false;
							col_moved_up = true;
						}
						updateCollision(hidden_map, tile_size, box.position.x, box.position.y, 0, window);
						if (col_velocity.y != 0.f && col_moved_up == false)
						{
							getHitbox().move({ 0.f, 1.0f });
							can_move_vertically = false;

						}
						updateCollision(hidden_map, tile_size, box.position.x, box.position.y, 2, window);
						if (col_velocity.x != 0.f)
						{
							getHitbox().move({ -1.0f,0.f });
							can_move_horizontally = false;
						}
						updateCollision(hidden_map, tile_size, box.position.x, box.position.y, 3, window);
						if (col_velocity.x != 0.f)
						{
							getHitbox().move({ 1.0f,0.f });
							can_move_horizontally = false;
						}

					}
				}

			}
		}
		level_count++;
	}


	


	syncSpriteWithHitbox();
		

	if (velocity.y < max_y_speed)
		velocity.y = max_y_speed;
		
	//} while (can_move_horizontally == false || can_move_vertically == false);
     applyGravity(gravity);
	 if (can_move_horizontally)
	 {
		 getHitbox().move({ velocity.x, 0.f });
	 }
	 if (can_move_vertically)
	 {
		 getHitbox().move({ 0.f, velocity.y });
	 }

	// simple horizontal friction
	velocity.x = (std::abs(velocity.x) < 0.1f) ? 0.f : velocity.x / 2.f;

	//if (col_velocity.x == 0.f)
	//{
	//	getHitbox().move({ velocity.x, 0.f });
	//	std::cout << velocity.x << std::endl;
	//}
	//else
	//{
	//	do
	//	{
	//		getHitbox().move({ col_velocity.x, 0.f });
	//		syncSpriteWithHitbox();
	//		updateCollision(map, tile_size, true,window);
	//	} while (col_velocity.x != 0);
	//}

	//updateCollision(map, tile_size, false,window);

	//if (col_velocity.y == 0.f) // 
	//{
	//	getHitbox().move({ 0.f, velocity.y });
	//	grounded = false;
	//}
	//else
	//{
	//	do
	//	{
	//		getHitbox().move({ 0.f, col_velocity.y });
	//		syncSpriteWithHitbox();
	//		grounded = true;
	//		updateCollision(map, tile_size, false,window);
	//	} while (col_velocity.y != 0);
	//}

	//applyGravity(gravity);

	//// simple horizontal friction
	//velocity.x = (std::abs(velocity.x) < 0.1f) ? 0.f : velocity.x / 2.f;

}

void PlayerCharacter::updateCollision(std::vector<Level>& map, float tile_size, float box_x, float box_y, int check, sf::RenderWindow& window)
{
	col_velocity = { 0.f,0.f };

	int level_count = 0;


	//for (Level& level : map)
	//{
	//	for (int row_num{ 0 }; row_num < level.getHeight(); row_num++)
	//	{
	//		for (int col_num{ 0 }; col_num < level.getWidth(); col_num++)
	//		{
				//top
				float tile_y = box_y;
				float tile_x = box_x;
				float width = getHitbox().getGlobalBounds().size.x/3;
				float height = getHitbox().getGlobalBounds().size.y / 2;
				float x = getHitbox().getPosition().x + width + 2;
				float y = getHitbox().getPosition().y;

				//bottom
				if (check == 1)
				{
					width = getHitbox().getGlobalBounds().size.x / 3;
					height = getHitbox().getGlobalBounds().size.y / 2;
					x = getHitbox().getPosition().x + width + 2;
					y = getHitbox().getPosition().y + height;
				}
				//right
				if (check == 2)
				{
					width = getHitbox().getGlobalBounds().size.x / 2;
					height = getHitbox().getGlobalBounds().size.y / 3;
					x = getHitbox().getPosition().x + width + 2;
					y = getHitbox().getPosition().y + height;
				}
				//left
				if (check == 3)
				{
					width = getHitbox().getGlobalBounds().size.x / 2;
					height = getHitbox().getGlobalBounds().size.y / 3;
					x = getHitbox().getPosition().x;
					y = getHitbox().getPosition().y + height;
				}
				sf::RectangleShape player_rect(sf::Vector2f{ width, height });
				player_rect.setPosition(sf::Vector2f{ x, y });
				window.draw(player_rect);
				//if (level.getTile(col_num, row_num) == 1) // 1 == tile
				//{
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
						//std::cout << col_velocity.x << "," << col_velocity.y << std::endl;
					}
				//}
			//}
		//}
		//level_count++;
	///}

	
}

void PlayerCharacter::MapSegmentCollision(std::vector<Level>& map, float tile_size, int check, sf::RenderWindow& window)
{
	//updateCollision(map, tile_size, 0, window);
	//if (col_velocity.y != 0.f)
	//{
	//	getHitbox().move({ 0.f, 1.0f });
	//	can_move_vertically = false;

	//}
	//updateCollision(map, tile_size, 1, window);
	//if (col_velocity.y != 0.f)
	//{
	//	getHitbox().move({ 0.f, -1.0f });
	//	grounded = true;
	//	can_move_vertically = false;
	//}
	//else
	//{
	//	grounded = false;
	//}
	//updateCollision(map, tile_size, 2, window);
	//if (col_velocity.x != 0.f)
	//{
	//	getHitbox().move({ -1.0f,0.f });
	//	can_move_horizontally = false;
	//}
	//updateCollision(map, tile_size, 3, window);
	//if (col_velocity.x != 0.f)
	//{
	//	getHitbox().move({ 1.0f,0.f });
	//	can_move_horizontally = false;
	//}
	//syncSpriteWithHitbox();
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

		//printf("jumping\n");
		velocity.y = -jump_power / 3;
		grounded = false;
	} else {
	
	}
}

void PlayerCharacter::applyGravity(float& gravity)
{
	if (!grounded)
	{	
		//printf("not grounded\n");
		velocity.y += 1;
	}
	else {
		velocity.y = 0;
		//printf("grounded\n");
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
