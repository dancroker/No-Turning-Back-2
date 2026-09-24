#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

#include <SFML/Audio.hpp>

#include "../OwnSound.hpp"
#include "../Map/LevelGen/Level.hpp"

class PlayerCharacter : public GameObject
{
public:

	void init() override;
	void update(float& gravity, std::vector<Level>& map, float tile_size);
	void updateCollision(std::vector<Level>& map, float tile_size);
	
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
	OwnSound sound;



private:
	std::unique_ptr<sf::View> player_camera{ std::make_unique<sf::View>() };
	sf::Vector2f col_velocity{ 0.f, 0.f };
	bool grounded{ false };
	float speed{ 50.f };
	float jump_power{ 50.f };
	
};