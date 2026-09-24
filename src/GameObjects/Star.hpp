#pragma once

#include "GameObject.hpp"

class Star : public GameObject
{
public:

	void init(sf::Texture& new_texture);
	void update() override;

private:

};
