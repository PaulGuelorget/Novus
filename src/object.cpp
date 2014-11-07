#include "Headers/object.hpp"

//data_objects* 	mData_Objects

#include "../Media/Codes/Objects/objects_database"

Object::Object()/*(sf::RenderWindow& window, std::string name, int x, int y):
mWindow(window),
mname(name),
mx(x),
my(y)*/
{
	/*mname = name;
	if (mname=="heart")
	{
		if(!mTexture.loadFromFile("../../Media/Images/Objects/heart.png"))
		{
			// Handle loading error
		}
	}
	else if (mname=="mana")
	{
		if(!mTexture.loadFromFile("../../Media/Images/Objects/mana.png"))
		{
			// Handle loading error
		}
	}
	else
	{
		if(!mTexture.loadFromFile("../../Media/Images/Objects/heart.png"))
		{
			// Handle loading error
		}
	}
	mx=x;
	my=y;
	*/
}

Object::~Object()
{

}

void Object::draw()
{
	mSprite.setTexture(mTexture);
	mSprite.setPosition(mx,my);
	//mWindow.draw(mSprite);
}

void Object::set_x(int new_x)
{
	mx=new_x;
}

void Object::set_y(int new_y)
{
	my=new_y;
}

int Object::get_x()
{
	return mx;
}


int Object::get_y()
{
	return my;
}

sf::Sprite Object::get_sprite()
{
	return mSprite;
}

void Object::set_name(std::string string)
{
	mname=string;
}
void Object::set_texture(std::string string)
{
	if (!mTexture.loadFromFile(string))
		{
			fprintf(stderr,"FATAL ERROR POTO");
		}
}

sf::Texture Object::get_texture()
{
	return mTexture;
}

std::string Object::get_name()
{
	return mname;
}

void Object::set_map(int nmap)
{
	mmap_number = nmap;
}

int Object::get_map()
{
	return mmap_number;
}

// Fonction de travail sur la structure permettant d'accéder aux objets


std::string name_to_adress(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].adress;
		}
	}
}


char name_to_type(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].type;
		}
	}
}

bool name_to_immediate(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].immediate;
		}
	}
}

int name_to_health(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].health;
		}
	}	
}
int name_to_mana(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].mana;
		}
	}	
}
int name_to_attack(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].attack;
		}
	}
}
int name_to_defense(std::string value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].name==value)
		{
			return Data_Objects[i].defense;
		}
	}
}

std::string type_to_name(char value)
{
	for (int i=0; i<NUMBER_OBJECT; i++)
	{
		if(Data_Objects[i].type==value)
		{
			return Data_Objects[i].name;
		}
	}
}