#include "Headers/game.hpp"
#define HAUTEUR 900
#define LARGEUR 900
#define X 200
#define Y 200
#include <stdexcept>
#include <iostream>

using namespace std;

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
/*
  sf::Window App(sf::VideoMode(LARGEUR, HAUTEUR), "Novus");
  Map map("../../Media/Maps/map");
  map.print_map();
  while (App.isOpen()) 
  {
    sf::Event Event;
    while (App.pollEvent(Event))
    {
    	if (Event.type == sf::Event::Closed)
   		{
			App.close();
		}
	}

    App.display();
  }
  return EXIT_SUCCESS;
}

*/