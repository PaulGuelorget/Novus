#include "Headers/world.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window, string Filename)
: mWindow(window)
, mMap(window, Filename)
, mCharacter(window, mMap)
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)

{

	mFont.loadFromFile("../../Media/Fonts/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);

	loadTextures();
	buildScene();
}

void World::update(sf::Time dt)
{
}

void World::draw()
{
    mMap.draw();
    mCharacter.draw();
    mWindow.draw(mStatisticsText);

}

void World::handle(sf::Keyboard::Key key, bool b)
{
	mCharacter.set_character(key, b);
}

void World::loadTextures()
{
}

void World::buildScene()
{}


void World::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Life: " + toString(mCharacter.get_life()) + "\n" +
			"Mana: " + toString(mCharacter.get_mana()) + "\n" +
			"X: " + toString(mCharacter.get_x()) + "\n" +
			"Y: " + toString(mCharacter.get_y()) + "\n" +
			"X_TL: " + toString(mMap.get_x_tl()) + "\n" +
			"Y_TL: " + toString(mMap.get_y_tl()) + "\n"
			);
							 
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}