#include "Headers/menu.hpp"

const sf::Time Menu::TimePerFrame = sf::seconds(1.f/60.f);

Menu::Menu(): mWindow(sf::VideoMode(WIDTH, HEIGHT), "Novus")
{
	sf::Image icon;
    if (!icon.loadFromFile("../../Media/Images/icon.png"))
    {}
    mWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	if (!Tmenu.loadFromFile("../../Media/Images/menu.png"))
	{}

}

void Menu::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);

		}
		render();
	}
}

void Menu::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void Menu::render()
{	
	mWindow.clear();
	mWindow.setView(mWindow.getDefaultView());
	draw();
	mWindow.display();
}


void Menu::update(sf::Time elapsedTime)
{
}

Menu::~Menu()
{

}

void Menu::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (!isPressed)
	{
		if (key==sf::Keyboard::Return)
		{
			try
			{
				Game game(mWindow);
				game.run();
			}
			catch (std::exception& e)
			{
				std::cout << "\nEXCEPTION: " << e.what() << std::endl;
			}

		}
	}
}

void Menu::draw()
{
	Smenu.setTexture(Tmenu);
	Smenu.setPosition(0,0);
	mWindow.draw(Smenu);
}