#include "Headers/map.hpp"



Ground grounds[SIZE_GROUNDS]={

{.enum_name=Sand,.adress="../../Media/Images/sand.png",.identifier_in_map='S',.obstacle=false,.change_velocity=false,.change_level=false},
{.enum_name=Grass,.adress="../../Media/Images/grass.png",.identifier_in_map='G',.obstacle=false,.change_velocity=false,.change_level=false},
{.enum_name=Water,.adress="../../Media/Images/water.png",.identifier_in_map='W',.obstacle=true,.change_velocity=false,.change_level=false},
{.enum_name=Tree,.adress="../../Media/Images/forest.png",.identifier_in_map='T',.obstacle=true,.change_velocity=false,.change_level=false},
{.enum_name=Grass,.adress="../../Media/Images/grass.png",.identifier_in_map='O',.obstacle=false,.change_velocity=false,.change_level=false},
{.enum_name=Mountain,.adress="../../Media/Images/mountain.png",.identifier_in_map='M',.obstacle=false,.change_velocity=true,.change_level=false,.new_velocity=3},
{.enum_name=Flower,.adress="../../Media/Images/flower.png",.identifier_in_map='F',.obstacle=false,.change_velocity=false,.change_level=false},
{.enum_name=Hole,.adress="../../Media/Images/hole.png",.identifier_in_map='H',.obstacle=false,.change_velocity=false,.change_level=true,.code_of_other_level=1,.adress_of_other_level="../../Media/Maps/map2",.x_tl=0,.y_tl=0,.x=100,.y=100},
{.enum_name=Hole2,.adress="../../Media/Images/hole.png",.identifier_in_map='I',.obstacle=false,.change_velocity=false,.change_level=true,.code_of_other_level=2,.adress_of_other_level="../../Media/Maps/map",.x_tl=-640,.y_tl=-626,.x=525,.y=310}

};

Map::Map(sf::RenderWindow& window, string Filename):
mWindow(window)
,mFilename(Filename)
{
	ifstream File(mFilename);

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
				map_matrix[i*m_largeur+j]=identifier_to_name(element);
			}
			char element_inutile;
			File >> element_inutile;
		}
		load_textures();
	}
	else
	{
		cout << "ERROR : Impossible to find the file." << endl;
	}
	x_tl=0;
	y_tl=0;
}

Map::~Map()
{
	free(map_matrix);
}

void Map::reset_filename(std::string new_filename, int new_x_tl, int new_y_tl)
{
	mFilename = new_filename;
	ifstream File(mFilename);
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
				map_matrix[i*m_largeur+j]=identifier_to_name(element);
			}
			char element_inutile;
			File >> element_inutile;
		}
		load_textures();
	}
	else
	{
		cout << "ERROR : Impossible to find the file." << endl;
	}
	x_tl=new_x_tl;
	y_tl=new_y_tl;

	// To add: ennemies reinitialization here when they will exist
}
void Map::print_map()
{
	for (int i=0; i<m_hauteur; i++)
	{
		for (int j=0; j<m_largeur; j++)
		{
			printf("%c ", name_to_identifier(map_matrix[i*m_largeur+j]));
		}
		printf("\n");
	}
}

MAP* Map::get_map_matrix()
{
	return map_matrix;
}

int Map::get_m_hauteur()
{
	return 30*m_hauteur;
}
int Map::get_m_largeur()
{
	return 30*m_largeur;
}

int Map::get_x_tl()
{
	return x_tl;
}
int Map::get_y_tl()
{
	return y_tl;
}

void Map::set_x_tl(int new_x_tl)
{
	x_tl=new_x_tl;
}
void Map::set_y_tl(int new_y_tl)
{
	y_tl=new_y_tl;
}

void Map::draw()
{
	set_textures();
	for (int i=0; i<m_hauteur; i++)
	{
		for (int j=0; j<m_largeur; j++)
		{

			for (int l=0; l<SIZE_GROUNDS; l++)
			{
				if (map_matrix[i*m_hauteur+j] == grounds[l].enum_name )
				{
					(grounds[l].sprite).setPosition(x_tl+30*j,y_tl+30*i);
					mWindow.draw(grounds[l].sprite);
				}
			}
}
}
}

MAP Map::get_elem_by_matrix_coordinates( int x, int y)
{
	return map_matrix[x+m_largeur*y];
}

MAP Map::get_elem_by_in_game_coordinates( int x, int y)
{
	return get_elem_by_matrix_coordinates(x/30, y/30);
// Si l'on veut récupérer via les coordonnees dans le jeu et non sur la matrice de la map il suffit de diviser par 30 et de prendre la partie entière du résultat. Ici ça marche car une division d'int prend la partie entière.

}




char name_to_identifier(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if (grounds[i].enum_name==value)
		{
			return grounds[i].identifier_in_map;
		}
	}
}

MAP identifier_to_name(char value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if (grounds[i].identifier_in_map==value)
		{
			return grounds[i].enum_name;
		}
	}
}

bool name_to_obstacle(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].obstacle;
		}
	}
}
bool name_to_change_level(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].change_level;
		}
	}
}
void load_textures()
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if (!(grounds[i].texture).loadFromFile(grounds[i].adress))
		{
		}
	}
}

void set_textures()
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		(grounds[i].sprite).setTexture(grounds[i].texture);
	}
}

std::string name_to_adress_of_other_level(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].adress_of_other_level;
		}
	}	
}


bool name_to_change_velocity(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].change_velocity;
		}
	}	
}
int name_to_new_velocity(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].new_velocity;
		}
	}
}

int name_to_x_tl(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].x_tl;
		}
	}
}

int name_to_y_tl(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].y_tl;
		}
	}
}

int name_to_x(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].x;
		}
	}
}

int name_to_y(MAP value)
{
	for (int i=0; i<SIZE_GROUNDS; i++)
	{
		if(grounds[i].enum_name==value)
		{
			return grounds[i].y;
		}
	}
}