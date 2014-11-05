#include "Headers/world.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window, string Filename)
: mWindow(window)
, mMap(window, Filename)
, mCharacter(window, mMap)
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
/*, mObject(window,"heart",100,100)*/
{
	mFont.loadFromFile("../../Media/Fonts/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
	loadTextures();
	buildScene();
	mObjects = (Object**)malloc(sizeof(Object*)*NUMBER_OBJECT);
	FillObjects("../../Media/Objects/object1");
}

World::~World()
{
	free(mObjects);
}
void World::update(sf::Time dt)
{
	updateObjects();
	CharacterAndObjectsInteraction();
}

void World::draw()
{
    mMap.draw();
    drawObjects();
    mCharacter.draw();
    mWindow.draw(mStatisticsText);
}

void World::handle(sf::Keyboard::Key key, bool b)
{
	mCharacter.set_character(key, b);
}

void World::loadTextures()
{
}

void World::buildScene()
{}


void World::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Life: " + toString(mCharacter.get_life()) + "\n" +
			"Mana: " + toString(mCharacter.get_mana()) + "\n" +
			"X: " + toString(mCharacter.get_x()) + "\n" +
			"Y: " + toString(mCharacter.get_y()) + "\n" +
			"X_TL: " + toString(mMap.get_x_tl()) + "\n" +
			"Y_TL: " + toString(mMap.get_y_tl()) + "\n"
			);
							 
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void World::updateObjects()
{
	// Mise à jour de la position de l'objet
	//for (int i=0; i<NUMBER_OBJECT; i++)
	//{
	//	mObject.set_x(mMap.get_x_tl()+mObject.get_x());
	//	mObject.set_y(mMap.get_y_tl()+mObject.get_y());	
	//}

	
  // Si le perso touche l'objet alors l'objet disparaît du tableau des objets
  // On fera ça à grand renforts de get_character_x etc .
}

void World::FillObjects(std::string Filename)
{
	ifstream File(Filename);

	if (File)
	{
		double tmp_number_of_objects;
		File >> tmp_number_of_objects;
		number_of_objects=(int)tmp_number_of_objects;
		int nmap;
		char type;
		double x, y;
		for (int i=0; i<number_of_objects; i++)
		{
			mObjects[i]=(Object*)malloc(sizeof(Object));
			File >> nmap;
			File >> type;
			mObjects[i]->set_map((int)nmap);
			File >> x;
			File >> y;
			if (mMap.get_map_number()!=mObjects[i]->get_map())
			{
				x=-100;
				y=-100; // A first naive solution: if the object is not supposed to be on the current map, then it is loaded in a place the character can not go for collision reasons.
			}

			mObjects[i]->set_x((int)x);
			mObjects[i]->set_y((int)y);
			mObjects[i]->set_name(type_to_name(type));

		}
	}
	else
	{
		cout << "ERROR : Impossible to find the file." << endl;
	}
}

void World::drawObjects()
{
	sf::Texture texture;
	sf::Sprite sprite;
	for (int i=0; i<number_of_objects; i++)
	{
		texture.loadFromFile(name_to_adress(mObjects[i]->get_name()));
		sprite.setTexture(texture);
		sprite.setPosition(mMap.get_x_tl()+mObjects[i]->get_x(),mMap.get_y_tl()+mObjects[i]->get_y());
		mWindow.draw(sprite);
	}
}

bool World::is_collising(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2)
{
	if (y2-h1<= y1 && y1 <= y2+h2 && x2-w1<=x1 && x1<=x2+w2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void World::CharacterAndObjectsInteraction()
{
	for (int i=0; i<number_of_objects;i++)
	{
		if (is_collising(-mMap.get_x_tl()+mCharacter.get_x(),-mMap.get_y_tl()+mCharacter.get_y(),HEIGHT_CHARACTER,WIDTH_CHARACTER, mObjects[i]->get_x(), mObjects[i]->get_y(), HEIGHT_OBJECTS, WIDTH_OBJECTS ))
		{
			mCharacter.dealWithObjects(*mObjects[i]);
			if (name_to_immediate(mObjects[i]->get_name()) || mCharacter.get_number_of_objects() < mCharacter.get_max_number_of_objects() )
			{
				mObjects[i]->set_name("Empty");
			}
		}
	}
}