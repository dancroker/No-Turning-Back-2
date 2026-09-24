#include "AnimationManager.hpp"

AnimationManager::AnimationManager(sf::String texture_path, int frame_width, int frame_height, int num_frames, int current_frame)
	: frame_width(frame_width), frame_height(frame_height), num_frames(num_frames), current_frame(current_frame), animation_sprite(animation_texture)
{
	if(!animation_texture.loadFromFile(std::filesystem::path(texture_path)))
	{
		std::cout << "FAIL!!!!";
	}
	animation_sprite.setTexture(animation_texture);
	animation_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { frame_width, frame_height }));
	animation_clock.restart();
}

AnimationManager::~AnimationManager() {} 

int& AnimationManager::play()
{
	if (animation_clock.getElapsedTime().asSeconds() >= time_per_frame)
	{
		if (current_frame >= num_frames)
		{
			current_frame = 0;
			loop_count++;
		}
		else
		{
			current_frame++;
		}
		int x = texture_rect_position.x + (frame_width * current_frame);
		int y = texture_rect_position.y;
		animation_sprite.setTextureRect(sf::IntRect({ x, y }, { frame_width, frame_height }));
		animation_clock.restart();
	}
	return loop_count;
}

void AnimationManager::setTextureRect(float x, float y)
{
	texture_rect_position.x = x;
	texture_rect_position.y = y;
}