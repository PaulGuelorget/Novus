#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "object.hpp"
#define MAX_OBJECTS 500

class Inventory
{
public:
								Inventory(sf::RenderWindow& window);
								~Inventory();
	void						draw();
	void 						add(std::string value);
	std::string 				get_inventory(int i);
/* On imaginera une fonction du type :
	void 				insert_in_inventory();
*/
private:
	sf::RenderWindow& 			mWindow;
	sf::Texture 				Main_texture;
	sf::Sprite					Main_sprite;
	std::vector<std::string>	inventory;

};

#endif