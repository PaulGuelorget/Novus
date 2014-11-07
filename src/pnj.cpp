#include "Headers/Pnj.hpp"

//Data_PNJ* 	mData_PNJ

#include "../Media/Codes/Pnj/Pnj_database"

Pnj::Pnj()
{
}

Pnj::~Pnj()
{

}

void Pnj::draw()
{
	mSprite.setTexture(mTexture);
	mSprite.setPosition(mx,my);
	fprintf(stderr,"%d %d",mx,my);
	//mWindow.draw(mSprite);
}

void Pnj::set_x(int new_x)
{
	mx=new_x;
}

void Pnj::set_y(int new_y)
{
	my=new_y;
}

int Pnj::get_x()
{
	return mx;
}


int Pnj::get_y()
{
	return my;
}

sf::Sprite Pnj::get_sprite()
{
	return mSprite;
}

void Pnj::set_name(std::string string)
{
	mname=string;
}
void Pnj::set_texture(std::string string)
{
	if (!mTexture.loadFromFile(string))
		{
			fprintf(stderr,"FATAL ERROR POTO");
		}
}

sf::Texture Pnj::get_texture()
{
	return mTexture;
}

std::string Pnj::get_name()
{
	return mname;
}

void Pnj::set_map(int nmap)
{
	mmap_number = nmap;
}

int Pnj::get_map()
{
	return mmap_number;
}

// Fonction de travail sur la structure permettant d'accéder aux objets









void Pnj::behave()
{
	if (PNJ::name_to_behavior(mname)==FRIENDLY)
	{
		int nombre_aleatoire = 0;
		srand(time(NULL));
		nombre_aleatoire = rand() % 4;
		if (nombre_aleatoire == 0 && ((clock.getElapsedTime()).asSeconds() >= 5))
		{
			mx=mx+PNJ::name_to_velocity(mname);
			clock.restart();
		}
		else if (nombre_aleatoire == 1 && ((clock.getElapsedTime()).asSeconds() >= 5))
		{
			mx=mx-PNJ::name_to_velocity(mname);
			clock.restart();
		}
		else if (nombre_aleatoire == 2 && ((clock.getElapsedTime()).asSeconds() >= 5))
		{
			my=my+PNJ::name_to_velocity(mname);
			clock.restart();

		}
		else if (nombre_aleatoire == 3 && ((clock.getElapsedTime()).asSeconds() >= 5))
		{
			my=my+PNJ::name_to_velocity(mname);
			clock.restart();
		}

	}
	else if (PNJ::name_to_behavior(mname)==AGGRESSIVE)
	{

	}
}







namespace PNJ
{

std::string name_to_adress(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].adress;
		}
	}
}


char name_to_type(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].type;
		}
	}
}

int name_to_health(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].health;
		}
	}	
}
int name_to_mana(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].mana;
		}
	}	
}
int name_to_attack(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].attack;
		}
	}
}
int name_to_defense(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].defense;
		}
	}
}

std::string type_to_name(char value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].type==value)
		{
			return Data_PNJ[i].name;
		}
	}
}

int name_to_velocity(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].velocity;
		}
	}	
}

BEHAVIOR name_to_behavior(std::string value)
{
	for (int i=0; i<NUMBER_PNJ; i++)
	{
		if(Data_PNJ[i].name==value)
		{
			return Data_PNJ[i].behavior;
		}
	}	
}

}

