#include "Game.hpp"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
	srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
	text_hello_world.setString("Hello, World!");
	map.generate(5); 

	return true;
}

void Game::update()
{
	// TODO: add a switch with enum for gamestate
}

void Game::render()
{
	window.clear(sf::Color{ 100, 149, 237, 255 });

	window.draw(text_hello_world);

	map.draw_map(window);
}