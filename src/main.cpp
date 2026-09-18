#include <cstdlib>

#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode({ 1080, 720 }), "Hello World!", sf::Style::Close, sf::State::Windowed);
  window.setFramerateLimit(60);
  sf::Image window_icon;
  (void)window_icon.loadFromFile("./data/images/icon.png");
  window.setIcon(window_icon);

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

    window.display();
  }
  
  return EXIT_SUCCESS;
}