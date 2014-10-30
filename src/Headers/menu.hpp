#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

using namespace std;

class Menu
{
public:
							Menu();
							~Menu();
	void					processEvents();
	void 					run();
	void					update(sf::Time elapsedTime);
	void					render();
	void 					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void 					draw();

private:
	static const sf::Time	TimePerFrame;
	sf::RenderWindow		mWindow;
    sf::Texture 			Tmenu;
    sf::Sprite  			Smenu;
};
#endif