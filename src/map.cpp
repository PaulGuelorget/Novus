#include "Headers/map.hpp"

Map::Map(sf::RenderWindow& window, string Filename):
mWindow(window)
{
	ifstream File(Filename);

	if (File)
	{
		// Getting data from a file to a matrix named map_matrix containing information about the ground
		double d_m_largeur, d_m_hauteur;
		File >> d_m_largeur;
		File >> d_m_hauteur;
		m_largeur = (int)d_m_largeur;
		m_hauteur = (int)d_m_hauteur;
		map_matrix=(MAP*)malloc(m_largeur*m_hauteur*(sizeof(MAP)));
		for (int i=0; i<m_hauteur; i++)
		{
			for (int j=0; j<m_largeur; j++)
			{
				char element;
				File >> element;
				map_matrix[i*m_largeur+j]=map_return(element);
			}
			char element_inutile;
			File >> element_inutile;
		}

		// Getting the textures of the ground
		if (!Tmsand.loadFromFile("../../Media/Images/sand.png"))
		{
		// Handle loading error
		}
		if (!Tmgrass.loadFromFile("../../Media/Images/grass.png"))
		{
		// Handle loading error
		}
		if (!Tmtree.loadFromFile("../../Media/Images/forest.png"))
		{
		// Handle loading error
		}
	}
	else
	{
		cout << "ERROR : Impossible to find the file." << endl;
	}
}

Map::~Map()
{
	free(map_matrix);
}

void Map::print_map()
{
	//cout << m_largeur << " de large et " << m_hauteur << " de haut " <<endl;
	for (int i=0; i<m_hauteur; i++)
	{
		for (int j=0; j<m_largeur; j++)
		{
			printf("%c ", ground_from_map(map_matrix[i*m_largeur+j]));
		}
		printf("\n");
	}
}

MAP map_return(char element)
{
	switch (element)
	{
		case 'T':
			return Tree;
		case 'G':
			return Grass;
		case 'S':
			return Sand;
		default:
			return Grass;
	}
}

char ground_from_map(MAP element_map)
{
	switch (element_map)
	{
		case Tree:
			return 'T';
		case Grass:
			return 'G';
		case Sand:
			return 'S';
		default:
			return 'G';
	}
}
/*
void Map::draw(sf::RenderWindow* window)
{
	for (int i=0; i<m_largeur; i++)
	{
		for (int j=0; j<m_hauteur; j++)
		{
			(MAP_to_sprite(map_matrix[i*m_largeur+j])).setTexture(MAP_to_texture(map_matrix[i*m_largeur+j]));
			(MAP_to_sprite(map_matrix[i*m_largeur+j])).setPosition(30*i, 30*j);
			*window.draw(MAP_to_sprite(map_matrix[i*m_largeur+j]));
		}
	}
}
*/
sf::Texture Map::MAP_to_texture(MAP map)
{
	switch (map)
	{
		case Tree:
			return Tmtree;
		case Grass:
			return Tmgrass;
		case Sand:
			return Tmsand;
		default:
			return Tmgrass;
	}
}

sf::Sprite Map::MAP_to_sprite(MAP map)
{
	switch (map)
	{
		case Tree:
			return Smtree;
		case Grass:
			return Smgrass;
		case Sand:
			return Smsand;
		default:
			return Smgrass;
	}
}

MAP* Map::get_map_matrix()
{
	return map_matrix;
}

int Map::get_m_hauteur()
{
	return m_hauteur;
}
int Map::get_m_largeur()
{
	return m_largeur;
}


void Map::draw()
{
	Smgrass.setTexture(Tmgrass);
	Smsand.setTexture(Tmsand);
	Smtree.setTexture(Tmtree);

	for (int i=0; i<m_largeur; i++)
	{
		for (int j=0; j<m_hauteur; j++)
		{
			switch (map_matrix[i*m_hauteur+j])
			{
				case Grass:
					Smgrass.setPosition(30*j,30*i);
					mWindow.draw(Smgrass);
					break;
				case Sand:
					Smsand.setPosition(30*j,30*i);
					mWindow.draw(Smsand);
					break;
				case Tree:
					Smtree.setPosition(30*j,30*i);
					mWindow.draw(Smtree);
					break;
				default:
					Smgrass.setPosition(30*j,30*i);
					mWindow.draw(Smgrass);
					break;

			}
}
}
}