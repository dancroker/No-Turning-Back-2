#pragma once

#include <string>
#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class OwnSound {

	public:
		OwnSound();
		~OwnSound();
		bool loadPlaySound(std::string filename);
		bool loadPlayMusic();








	private:
	std::unique_ptr<sf::Sound> sound;
	sf::SoundBuffer buffer;
	std::unique_ptr<sf::Music> music;





};