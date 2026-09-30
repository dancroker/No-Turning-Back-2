#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

#include <SFML/Audio.hpp>

#include "../Map/LevelGen/Level.hpp"


class PlayerCharacter : public GameObject
{
public:
	PlayerCharacter();
	~PlayerCharacter();

	void init() override;
	void update(float& gravity, std::vector<Level>& map, std::vector<Level>& hidden_map, float tile_size, sf::RenderWindow& window);
	void updateCollision(std::vector<Level>& map, float tile_size, float box_x, float box_y, int check, sf::RenderWindow& window);
	void MapSegmentCollision(std::vector<Level>& map, float tile_size, int check, sf::RenderWindow& window);
	
	void centerCamera();

	void moveLeft();
	void moveRight();
	void jump();

	void applyGravity(float& gravity);

	sf::View& getPlayerCamera() const;

	bool getGrounded() const;
	void setGrounded(bool new_grounded);
	float getSpeed() const;
	void setSpeed(float new_speed);
	float getJumpPower() const;
	void setJumpPower(float new_jump_power);
	void setPosition(const sf::Vector2f& new_position) { hitbox->setPosition(new_position); }
	sf::Vector2f getPosition() { return hitbox->getPosition(); }
	sf::FloatRect getGlobalBounds() { return hitbox->getGlobalBounds(); }

	void MOVEUPPP();



private:
	std::unique_ptr<sf::View> player_camera{ std::make_unique<sf::View>() };
	sf::Vector2f col_velocity{ 0.f, 0.f };
	bool grounded{ false };
	float speed{ 50.f };
	float jump_power{ 50.f };

	float max_y_speed{ -19.f };

	bool can_move_horizontally = true;
	bool can_move_vertically = true;

	bool col_moved_up = false;
	
	sf::SoundBuffer jump_sfx_sound_buffer;
	sf::Sound jump_sfx_sound;
};