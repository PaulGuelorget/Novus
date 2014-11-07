#ifndef PNJ_HPP
#define PNJ_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#define NUMBER_PNJ 100
#define HEIGHT_PNJS 30
#define WIDTH_PNJS 20

enum BEHAVIOR { SLEEPING, FRIENDLY, AGGRESSIVE};
typedef struct data_PNJ data_PNJ;

struct data_PNJ
{
	std::string name;
	std::string adress;
	BEHAVIOR behavior;
	bool talkative;
	std::string speech;
	int velocity;
	char type;
	int health;
	int mana;
	int defense;
	int attack;

};
namespace PNJ
{
std::string name_to_adress(std::string value);
char name_to_type(std::string value);
int name_to_health(std::string value);
int name_to_mana(std::string value);
int name_to_attack(std::string value);
int name_to_defense(std::string value);
std::string type_to_name(char value);
int name_to_velocity(std::string value);
BEHAVIOR name_to_behavior(std::string value);

}

class Pnj
{
public:
							Pnj(/*sf::RenderWindow& window, std::string name, int x, int y*/);
							~Pnj();
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
	void 					behave();

private:
	std::string 			mname;
	sf::Texture				mTexture;
	sf::Sprite 				mSprite;
	int 					mx;
	int 					my;
	int 					mmap_number;
	sf::Clock				clock;

};

#endif