#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include "world.hpp"
#include "stringhelpers.hpp"
#include "object.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Game : private sf::NonCopyable
{
	public:
								Game(sf::RenderWindow& window);
		void					run();
		

	private:
		void					processEvents();
		void					update(sf::Time elapsedTime);
		void					render();
		void					updateStatistics(sf::Time elapsedTime);	
		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		void 					dealWithObjects(Object object);



	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow&		mWindow;
        World                   mWorld;
	  	sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif // BOOK_GAME_HPP
