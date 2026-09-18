#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

int main()
{
  // setup window
  sf::RenderWindow window(sf::VideoMode({ 1080, 720 }), "No Turning Back 2", sf::Style::Close, sf::State::Windowed);
  window.setFramerateLimit(60);
  sf::Image window_icon;
  (void)window_icon.loadFromFile("./data/images/icon.png");
  window.setIcon(window_icon);

	// setup game
	Game game(window);
  if (!game.init())
  {
		printf("Failed to initialize game\n\0");
		return EXIT_FAILURE;
  }

	// main loop
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
      else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
      {
        switch (keyPressed->scancode)
        {
				case sf::Keyboard::Scan::Escape:
					window.close();
					break;
        }
      }
      
    }

		game.update();
		game.render();
    window.display();
  }
  
  return EXIT_SUCCESS;
}