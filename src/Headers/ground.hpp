#ifndef GROUND_HPP
#define GROUND_HPP
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#define SIZE_GROUNDS 100

enum MAP { Tree, Grass, Sand, Water, Mountain, Flower, Hole, Hole2 };

typedef struct Ground Ground;

struct Ground
{
	MAP enum_name;
	std::string adress; 
	char identifier_in_map;
	bool obstacle;
	bool change_velocity;
	bool change_level;
	int  code_of_other_level;
	std::string adress_of_other_level;
	sf::Texture texture;
	sf::Sprite sprite;
	int new_velocity;
	int x_tl;
	int y_tl;
	int x;
	int y;
};


char name_to_identifier( MAP value);
MAP identifier_to_name(char value);
bool name_to_obstacle(MAP value);
bool name_to_change_level(MAP value);
bool name_to_change_velocity(MAP value);
int name_to_new_velocity(MAP value);
std::string name_to_adress_of_other_level(MAP value);
void load_textures();
void set_textures();
int name_to_x_tl(MAP value);
int name_to_y_tl(MAP value);
int name_to_x(MAP value);
int name_to_y(MAP value);


#endif