#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.hpp"
#define HEIGHT_CHARACTER 19
#define WIDTH_CHARACTER 12

#include "../Media/Codes/Character/character_enum_position"
enum COLLISION { C_LEFT, C_RIGHT, C_TOP, C_BOTTOM, C_TOP_LEFT, C_TOP_RIGHT, C_BOTTOM_LEFT, C_BOTTOM_RIGHT, C_NONE };
sf::IntRect POSITION_to_IntRect(POSITION p);


class Character
{
public:
							Character(sf::RenderWindow& window, Map& map);
	void					draw();
	void					set_current_position(POSITION p);
	void 					set_character(sf::Keyboard::Key key, bool b);
	COLLISION				Collision();
	void					character_data(sf::Keyboard::Key key, bool b);
	int 					get_mana();
	int 					get_life();
	int 					get_x();
	int 					get_y();
	void 					set_x(int new_x);
	void 					set_y(int new_y);

private:
	sf::RenderWindow& 		mWindow;
	Map&					mMap;
	sf::Texture				Tcharacter;
	sf::Sprite				Scharacter;
	POSITION				mCurrent_position;
	int 					x;
	int 					y;
	int 					v;
	int 					life;
	int 					mana;
	sf::Clock				clock;
	bool 					was_just_typing;
};
#endif