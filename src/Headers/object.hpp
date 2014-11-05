#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#define NUMBER_OBJECT 100
#define HEIGHT_OBJECTS 15
#define WIDTH_OBJECTS 15
typedef struct data_objects data_objects;

struct data_objects
{
	std::string name;
	std::string adress;
	std::string description;
	bool 		immediate; // True if it is consumed as soon as the character walks on it and false if it goes to the inventory
	char 		type;
	bool		bonus_mana;
	int 		mana;
	bool 		bonus_attack;
	int 		attack;
	bool 		bonus_health;
	int 		health;
	bool 		bonus_defense;
	int 		defense;
};

std::string name_to_adress(std::string value);
char name_to_type(std::string value);
bool name_to_immediate(std::string value);
int name_to_health(std::string value);
int name_to_mana(std::string value);
int name_to_attack(std::string value);
int name_to_defense(std::string value);
std::string type_to_name(char value);


class Object
{
public:
							Object(/*sf::RenderWindow& window, std::string name, int x, int y*/);
							~Object();
	void 					draw();
	void 					set_x(int new_x);
	void 					set_y(int new_y);
	int						get_x();
	int 					get_y();
	sf::Sprite 				get_sprite();
	sf::Texture 			get_texture();
	void 					set_texture(std::string string);
	std::string 			get_name();
	void 					set_name(std::string string);
	int 					get_map();
	void 					set_map(int nmap);

private:
	std::string 			mname;
	sf::Texture				mTexture;
	sf::Sprite 				mSprite;
	int 					mx;
	int 					my;
	int 					mmap_number;
};

#endif