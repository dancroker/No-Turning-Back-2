#include <iostream>

#include "OwnSound.hpp"


OwnSound::OwnSound()
    : sound(buffer)
{
}

OwnSound::~OwnSound() {
}

//for sound effects
bool OwnSound::loadPlaySound(std::string filename) {
	
	// sf::SoundBuffer buffer;
	// sf::Sound sound(buffer);

	if (!buffer.loadFromFile(filename)) {
		std::cout << "Failed to load sound file: " << filename << std::endl;
		return false;
	}

	sound.setBuffer(buffer);
	sound.play();
	
	return true;
}

//for looping music
bool OwnSound::loadPlayMusic() {
	sf::Music music;
	if (!music.openFromFile("data/music/menu_music.wav")) {
		return false;
	}
	//else { return true; }  <-- this returns the function before anything else can be done
	
	music.play();  // <-- this will not run if the function returns too early
	music.setLooping(true);
	return true; // successful return goes on the end
}

