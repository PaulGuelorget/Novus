#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

using namespace std;

enum MAP { Tree, Grass, Sand };

//typedef vector<MAP> map_column;
//typedef vector<map_column> map_matrix;

MAP map_return(char element);

char ground_from_map(MAP element_map);

sf::Texture MAP_to_texture(MAP map);

class Map
{
public:
	explicit Map(sf::RenderWindow& window, string Filename);
	~Map();
	void print_map();
	//void draw(sf::RenderWindow* window);
	sf::Texture MAP_to_texture(MAP map);
	sf::Sprite MAP_to_sprite(MAP map);
	MAP* get_map_matrix();
	int get_m_hauteur();
	int get_m_largeur();
	void draw();

	//void set_sprites(int x, int y);


private:
	sf::RenderWindow& mWindow;
	MAP* map_matrix;
	sf::Texture Tmsand;
	sf::Texture	Tmgrass;
	sf::Texture	Tmtree;
	sf::Sprite Smsand;
	sf::Sprite Smgrass;
	sf::Sprite Smtree;

public:
	int m_hauteur;
	int m_largeur;
};

#endif