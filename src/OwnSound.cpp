#include <iostream>

#include "OwnSound.hpp"


OwnSound::OwnSound() {
	//sf::Sound sound(sf::SoundBuffer buffer);
}
OwnSound::~OwnSound() {
}

bool OwnSound::loadPlaySound(std::string filename) {
	sf::SoundBuffer buffer;
	sf::Sound sound(buffer);
	if (!buffer.loadFromFile(filename)) {
		std::cout << "Failed to load sound file: " << filename << std::endl;
		return false;
	}
	sound.setBuffer(buffer);
	sound.play();
	return true;
}

bool OwnSound::loadPlayMusic() {
	sf::Music music;
	if (!music.openFromFile("data/mainLoop.wav")) {
		return false;
	}
	else { return true; }
	music.play();
	music.setLoopPoints({ sf::seconds(9), sf::seconds(86) });
}

