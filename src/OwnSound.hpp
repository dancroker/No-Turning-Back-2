#include <SFML/Audio.hpp>

class OwnSound {

public:
	OwnSound();
	~OwnSound();
	bool loadPlaySound(std::string filename);







private:
	sf::SoundBuffer buffer;
	sf::Sound sound;





};