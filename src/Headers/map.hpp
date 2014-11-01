#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "ground.hpp"
#define HEIGHT 600
#define WIDTH 800

using namespace std;

sf::Texture MAP_to_texture(MAP map);

class Map
{
public:
	explicit 							Map(sf::RenderWindow& window, std::string Filename);
										~Map();
	void 								print_map();
	void 								reset_filename(string new_filename, int new_x_tl, int new_y_tl);
	MAP* 								get_map_matrix();
	int 								get_m_hauteur();
	int 								get_m_largeur();
	int									get_x_tl();
	int									get_y_tl();
	void								set_x_tl(int new_x_tl);
	void								set_y_tl(int new_y_tl);
	MAP 								get_elem_by_matrix_coordinates( int x, int y);
	MAP 								get_elem_by_in_game_coordinates(int x, int y);
	MAP 								get_top_type;
	MAP 								get_bottom_type;
	MAP 								get_left_type;
	MAP 								get_right_type;
	void 								draw();

private:
	sf::RenderWindow& 					mWindow;
	std::string 						mFilename;
	MAP* 								map_matrix;
	int 								m_hauteur;
	int 								m_largeur;
	int 								x_tl;
	int									y_tl;
};

#endif