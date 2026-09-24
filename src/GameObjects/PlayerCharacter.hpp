#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

class PlayerCharacter : public GameObject
{
public:

	void init() override;
	void update() override;

	void moveLeft();
	void moveRight();
	void jump();

	bool getGrounded() const;
	void setGrounded(bool new_grounded);
	float getSpeed() const;
	void setSpeed(float new_speed);
	float getJumpPower() const;
	void setJumpPower(float new_jump_power);

private:
	sf::View player_camera;

	bool grounded{ false };
	float speed{ 50.f };
	float jump_power{ 50.f };
	
};