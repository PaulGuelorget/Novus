#include "Headers/game.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game(sf::RenderWindow& window): mWindow(window)
, mWorld(mWindow, "../../Media/Maps/map")
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
	mFont.loadFromFile("../../Media/Fonts/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
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

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
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

void Game::update(sf::Time elapsedTime)
{
	mWorld.update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();
	mWindow.setView(mWindow.getDefaultView());
    mWorld.draw();
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	/*
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us"
			)
							 
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
	*/
	mWorld.updateStatistics(elapsedTime);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	mWorld.handle(key, isPressed);
}