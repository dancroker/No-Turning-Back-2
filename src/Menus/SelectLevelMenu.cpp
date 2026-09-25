#include "SelectLevelMenu.hpp"

SelectLevelMenu::SelectLevelMenu() : Title_text(font), Level_Number(font), Quit_option(font), background_main_menu_sprite(background_main_menu_texture)
{
	if (!font.openFromFile("data/fonts/MxPlus_IBM_VGA_8x16.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
	lock.setTexture("data/images/Lock.png");
}
SelectLevelMenu::~SelectLevelMenu()
{}
void SelectLevelMenu::render(sf::RenderWindow& window)
{
	window.draw(background_main_menu_sprite);
	window.draw(Title_text);

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(100, 100));
	box.setFillColor(sf::Color::White);
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(5);

	for (float x = 0; x < 4; x++)
	{
		for (float y = 0; y < 2; y++)
		{
			int box_selected = x + (y*4);
			if (box_selected < LevelsUnlocked)
			{
				if (box_selected == MenuSelection)
				{
					box.setFillColor(sf::Color::Green);
				}
				else
				{
					box.setFillColor(sf::Color::White);
				}
			}
			else
			{
				if (box_selected == MenuSelection)
				{
					box.setFillColor(sf::Color(200, 255, 200));
				}
				else 
				{
					box.setFillColor(sf::Color(200, 200, 200));
				}
			}
			Level_Number.setString(std::to_string(box_selected+1));
			Level_Number.setPosition({ 250.f + x * 150.f + 40.f, 200.f + y * 150.f + 40.f });
			box.setPosition({ 250.f + x * 150.f ,  200.f + y * 150.f });
			window.draw(box);
			window.draw(Level_Number);

			if (box_selected >= LevelsUnlocked)
			{
				lock.getSprite().setPosition({ 250.f + x * 150.f + 45.f, 200.f + y * 150.f + 40.f });
				lock.getSprite().setScale({ 0.25f,0.25f });
				window.draw(lock.getSprite());
			}
		}
	}
	window.draw(Level_Number);
}

void SelectLevelMenu::init()
{
	background_main_menu_texture.loadFromFile("data/images/Menu_background.png");
	background_main_menu_sprite.setTexture(background_main_menu_texture);
	Title_text = TextCreator(0, "Select Level To Play:", 50, sf::Color::White, sf::Vector2f(270, 80));
	Level_Number = TextCreator(0, "1", 20, sf::Color::Black, sf::Vector2f(350, 200));
	Quit_option = TextCreator(0, "Quit", 20, sf::Color::White, sf::Vector2f(350, 250));
}

void SelectLevelMenu::update()
{
	// Update the menu selection based on user input
	switch (MenuSelection)
	{
	case 0:
		break;
	case 1:
		break;
	default:
		break;
	}
}

int SelectLevelMenu::keyPressed(int direction)  // 0 = up, 1 = down, 2 = left, 3 = right, 4 = enter, 5 = escape
{
	if( MenuSelection == 0 && direction == 2 )
	{
		MenuSelection = 7;
	}
	else if (MenuSelection == 7 && direction == 3)
	{
		MenuSelection = 0;
	}
	else if (MenuSelection >= 4 && direction == 0)
	{
		MenuSelection = MenuSelection-4;
	}
	else if (MenuSelection < 4 && direction == 1)
	{
		MenuSelection = MenuSelection +4 ;
	}
	else
	{
		if (direction == 2) 
		{
			MenuSelection--;
		}
		if (direction == 3)
		{
			MenuSelection++;
		}
	}
	if(direction == 4 && MenuSelection < LevelsUnlocked)
	{
		return MenuSelection;
	}
	return -1;

}
void SelectLevelMenu::KeyReleased(sf::Event event)
{}
void SelectLevelMenu::setMenuSelection(int selection)
{
	MenuSelection = selection;
}
int SelectLevelMenu::getMenuSelection()
{
	return MenuSelection;
}
