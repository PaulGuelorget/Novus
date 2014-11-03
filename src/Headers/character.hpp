#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.hpp"
#define HEIGHT_CHARACTER 19
#define WIDTH_CHARACTER 12

enum POSITION { FRONT1, FRONT2, FRONT3, FRONT4, FRONT5, FRONT6, FRONT7, 
				LEFT1, LEFT2, LEFT3, LEFT4, LEFT5, LEFT6, LEFT7, 
				RIGHT1, RIGHT2, RIGHT3, RIGHT4, RIGHT5, RIGHT6, RIGHT7,  
				BACK1, BACK2, BACK3, BACK4, BACK5, BACK6, BACK7 };
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
	sf::Clock				clock_front;
	sf::Clock 				clock_back;
	sf::Clock 				clock_right;
	sf::Clock 				clock_left;
	bool 					was_just_typing_front;
	bool 					was_just_typing_back;
	bool 					was_just_typing_right;
	bool 					was_just_typing_left;
};
#endif