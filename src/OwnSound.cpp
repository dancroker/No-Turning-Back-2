#include <iostream>

#include "OwnSound.hpp"


OwnSound::OwnSound() {

}
OwnSound::~OwnSound() {
}

bool OwnSound::loadPlaySound(std::string filename) {
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile(filename)) {
		std::cout << "Failed to load sound file: " << filename << std::endl;
		return false;
	}
	sound.setBuffer(buffer);
	sound.play();
	return true;
}

bool OwnSound::loadPlayMusic(std::string filename) {
	sf::Music music;
	if (!music.openFromFile(filename)) {
		return false;
	}
	music.play();
	music.setLooping();
}

