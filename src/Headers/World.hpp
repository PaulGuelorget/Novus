#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "map.hpp"
#include "character.hpp"

#include "stringhelpers.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
	public:
		explicit							World(sf::RenderWindow& window, string Filename);
		void								update(sf::Time dt);
		void								draw();
		void 								handle(sf::Keyboard::Key key, bool b);
		void								updateStatistics(sf::Time elapsedTime);

	private:
		void								loadTextures();
		void								buildScene();

	private:
		sf::RenderWindow&					mWindow;
        Map                                 mMap;
        Character							mCharacter;
        sf::Font							mFont;
		sf::Text							mStatisticsText;
		sf::Time							mStatisticsUpdateTime;
		std::size_t							mStatisticsNumFrames;
};

#endif // BOOK_WORLD_HPP
