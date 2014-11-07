#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "map.hpp"
#include "character.hpp"
#include "pnj.hpp"
#include "object.hpp"

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
											~World();
		void								update(sf::Time dt);
		void								draw();
		void 								handle(sf::Keyboard::Key key, bool b);
		void								updateStatistics(sf::Time elapsedTime);

		// Concerning objects

		void 								updateObjects();
		void 								drawObjects();
		void 								FillObjects(std::string Filename);
		void								CharacterAndObjectsInteraction();

		// Concerning PNJs

		void 								updatePNJs();
		void 								drawPNJs();
		void 								FillPNJs(std::string Filename);
		void								CharacterAndPNJsInteraction();

		// Concerning collisions between two "things" in the game

		bool 								is_collising(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2);

	private:
		void								loadTextures();
		void								buildScene();

	private:
		sf::RenderWindow&					mWindow;
        Map                                 mMap;
        Character							mCharacter;
        Object**							mObjects;
        Object  							mObject;
        Pnj** 								mPNJs;
        Pnj 								mPNJ;
        sf::Font							mFont;
		sf::Text							mStatisticsText;
		sf::Time							mStatisticsUpdateTime;
		std::size_t							mStatisticsNumFrames;
		double 								number_of_objects;
		double 								number_of_PNJs;
};

#endif // BOOK_WORLD_HPP
