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

  // Delta Time
  sf::Clock clock;

  // main loop
  while (window.isOpen())
  {
    sf::Time time{ clock.restart() };
    float dt{ time.asSeconds() };

    // TODO: Mark my words, I *WILL* use window.handleEvents() and NO /RTC1 compiler bug will stand in my way!
    //       As soon as I figure out CMakePresets.json...
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        window.close();
      }
      else if (const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>())
      {
        game.getInputHandler().handleKeyPressed(*keyPressed);
      }
      else if (const sf::Event::KeyReleased* keyReleased = event->getIf<sf::Event::KeyReleased>())
      {
        game.getInputHandler().handleKeyReleased(*keyReleased);
      }
      else if (const bool& mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
      {
        game.getInputHandler().handleMouseButtonPressed(&mouseButtonPressed);
      }
      else if (const bool& mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
      {
        game.getInputHandler().handleMouseButtonReleased(&mouseButtonReleased);
      }
    }

    game.update(dt);
    game.render();
    window.display();
  }
  
  return EXIT_SUCCESS;
}
