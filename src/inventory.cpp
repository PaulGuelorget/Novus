#include "Headers/inventory.hpp"

Inventory::Inventory(sf::RenderWindow& window):
mWindow(window)
{
	if(!Main_texture.loadFromFile(
		#include "../Media/Codes/Inventory/main_inventory_sprite_name"
		))
	{
		// Handle loading error
	}
}

Inventory::~Inventory()
{

}

void Inventory::draw()
{
	Main_sprite.setTexture(Main_texture);
	Main_sprite.setPosition(50,50);
	sf::Texture texture;
	sf::Sprite sprite;
	mWindow.draw(Main_sprite);
	for (int i=0; i<inventory.size(); i++)
	{
		texture.loadFromFile(name_to_adress(inventory[i]));
		sprite.setTexture(texture);
		sprite.setPosition(60,70+i*20);
		mWindow.draw(sprite);
	}
}

void Inventory::add(std::string value)
{
	inventory.push_back(value);
}

std::string Inventory::get_inventory(int i)
{
	return inventory[i];
}