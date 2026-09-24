#pragma once
#include <SFML/Graphics.hpp>
class AnimationManager
{
public:
	AnimationManager(sf::String texture_path, int frame_width, int frame_height, int num_frames, int current_frame);
	~AnimationManager();
	sf::Sprite& play();
	void setTextureRect(float x, float y);
	void setPosition(float x, float y) { animation_sprite.setPosition(x, y); };
	void setScale(float x, float y) { animation_sprite.setScale(x, y); };
	void setOrigin(float x, float y) { animation_sprite.setOrigin(x, y); };
	int getLoopCount() { return loop_count; };

private:
	int frame_width;
	int frame_height;
	int num_frames;
	int current_frame;
	float time_per_frame =  0.077; // 15 frames per second .77 = 13
	sf::Texture animation_texture;
	sf::Sprite animation_sprite;
	sf::Clock animation_clock;
	sf::Vector2f texture_rect_position;

	int loop_count = 0;
};