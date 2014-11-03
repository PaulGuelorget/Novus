#include "Headers/character.hpp"

Character::Character(sf::RenderWindow& window, Map& map):
mWindow(window),
mMap(map)
{
	if(!Tcharacter.loadFromFile("../../Media/Images/character.png"))
	{
		// Handle loading error
	}
	mCurrent_position=FRONT4;
	x=WIDTH/2;
	y=HEIGHT/2;
	v=30;
	life=100;
	mana=100;
	was_just_typing_front = false;
	was_just_typing_back = false;
	was_just_typing_right = false;
	was_just_typing_left = false;
}

void Character::draw()
{
	Scharacter.setTexture(Tcharacter);
	Scharacter.setTextureRect(POSITION_to_IntRect(mCurrent_position));
	Scharacter.setPosition(x,y);
	mWindow.draw(Scharacter);
}

int Character::get_mana()
{
	return mana;
}

int Character::get_life()
{
	return life;
}

int Character::get_x()
{
	return x;
}

int Character::get_y()
{
	return y;
}


sf::IntRect POSITION_to_IntRect(POSITION p)
{
	switch (p)
	{
		case FRONT1:
			return sf::IntRect(101,127,16,24);
		case FRONT2:
			return sf::IntRect(124,128,16,24);
		case FRONT3:
			return sf::IntRect(148,129,16,24);
		case FRONT4:
			return sf::IntRect(171,129,16,24);
		case FRONT5:
			return sf::IntRect(194,130,16,24);
		case FRONT6:
			return sf::IntRect(218,128,16,24);
		case FRONT7:
			return sf::IntRect(241,127,16,24);
		case BACK1:
			return sf::IntRect(456,131,16,24);
		case BACK2:
			return sf::IntRect(480,132,16,24);
		case BACK3:
			return sf::IntRect(503,133,16,24);
		case BACK4:
			return sf::IntRect(527,134,16,24);
		case BACK5:
			return sf::IntRect(550,134,16,24);
		case BACK6:
			return sf::IntRect(574,132,16,24);
		case BACK7:
			return sf::IntRect(595,132,16,24);
		case RIGHT1:
			return sf::IntRect(787,128,16,23);
		case RIGHT2:
			return sf::IntRect(810,127,16,23);
		case RIGHT3:
			return sf::IntRect(835,127,16,23);
		case RIGHT4:
			return sf::IntRect(857,128,16,23);
		case RIGHT5:
			return sf::IntRect(881,127,16,23);
		case RIGHT6:
			return sf::IntRect(906,127,16,23);
		case RIGHT7:
			return sf::IntRect(906,128,16,23);
		case LEFT1:
			return sf::IntRect(929,103,16,23);
		case LEFT2:
			return sf::IntRect(905,102,16,23);
		case LEFT3:
			return sf::IntRect(880,102,16,23);
		case LEFT4:
			return sf::IntRect(858,103,16,23);
		case LEFT5:
			return sf::IntRect(834,103,16,23);
		case LEFT6:
			return sf::IntRect(810,102,16,23);
		case LEFT7:
			return sf::IntRect(787,103,16,23);
		default:
			return sf::IntRect(101,127,16,24);
	}
}

void Character::set_current_position(POSITION p)
{
	mCurrent_position = p;
}

void Character::set_character(sf::Keyboard::Key key, bool b)
{
	character_data(key,b);
	if (key==sf::Keyboard::Z)
	{
		if (!(Collision()==C_TOP) && !(Collision()==C_TOP_RIGHT) && !(Collision()==C_TOP_LEFT) )
		{
			if (-mMap.get_y_tl()<=0 )
			{
				y-=v;
			}
			else
			{
				if (-mMap.get_y_tl()+HEIGHT>=mMap.get_m_hauteur())
				{
					if (y>=HEIGHT/2)
					{
						y-=v;
					}
					else
					{
						mMap.set_y_tl(mMap.get_y_tl()+v);
					}
				}
				else
				{
					mMap.set_y_tl(mMap.get_y_tl()+v);
				}
			}
		}
		if (name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x,-mMap.get_y_tl()+y)) || name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER,-mMap.get_y_tl()+y)))
		{
			int remove_pix = -v;
			if (-mMap.get_y_tl()<=0 )
			{
				y-=remove_pix;
			}
			else
			{
				if (-mMap.get_y_tl()+HEIGHT>=mMap.get_m_hauteur())
				{
					if (y>=HEIGHT/2)
					{
						y-=remove_pix;
					}
					else
					{
						mMap.set_y_tl(mMap.get_y_tl()+remove_pix);
					}
				}
				else
				{
					mMap.set_y_tl(mMap.get_y_tl()+remove_pix);
				}
			}
		}

	}

	if (key==sf::Keyboard::S && b)
	{
		if (!(Collision()==C_BOTTOM) && !(Collision()==C_BOTTOM_LEFT) && !(Collision()==C_BOTTOM_RIGHT))
		{
			if (-mMap.get_y_tl()+HEIGHT>=mMap.get_m_hauteur())
			{
				y+=v;
			}
			else
			{
				if (-mMap.get_y_tl()<=0)
				{
					if (y<=HEIGHT/2)
					{
						y+=v;
					}
					else
					{
						mMap.set_y_tl(mMap.get_y_tl()-v);
					}
				}
				else
				{
					mMap.set_y_tl(mMap.get_y_tl()-v);
				}
			}
		}
		if (name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x,-mMap.get_y_tl()+y+HEIGHT_CHARACTER)) || name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER,-mMap.get_y_tl()+y+HEIGHT_CHARACTER)))
		{
			int remove_pix = -v;
			if (-mMap.get_y_tl()+HEIGHT>=mMap.get_m_hauteur())
			{
				y-=remove_pix;
			}
			else
			{
				if (-mMap.get_y_tl()<=0)
				{
					if (y<=HEIGHT/2)
					{
						y+=remove_pix;
					}
					else
					{
						mMap.set_y_tl(mMap.get_y_tl()-remove_pix);
					}
				}
				else
				{
					mMap.set_y_tl(mMap.get_y_tl()-remove_pix);
				}
			}
		}
	}
	if (key==sf::Keyboard::Q && b)
	{
		if (!(Collision()==C_LEFT) && !(Collision()==C_TOP_LEFT) && !(Collision()==C_BOTTOM_LEFT))
		{
			if (-mMap.get_x_tl()<=0)
			{
				x-=v;
			}
			else
			{
				if (-mMap.get_x_tl()+WIDTH>=mMap.get_m_largeur())
				{
					if (x>=WIDTH/2)
					{
						x-=v;
					}
					else
					{
						mMap.set_x_tl(mMap.get_x_tl()+v);
					}
				}
				else
				{
					mMap.set_x_tl(mMap.get_x_tl()+v);
				}
			}
		}
		if (name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x,-mMap.get_y_tl()+y)) || name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x,-mMap.get_y_tl()+y+HEIGHT_CHARACTER)))
		{
			int remove_pix=-v;
			if (-mMap.get_x_tl()<=0)
			{
				x-=remove_pix;
			}
			else
			{
				if (-mMap.get_x_tl()+WIDTH>=mMap.get_m_largeur())
				{
					if (x>=WIDTH/2)
					{
						x-=remove_pix;
					}
					else
					{
						mMap.set_x_tl(mMap.get_x_tl()+remove_pix);
					}
				}
				else
				{
					mMap.set_x_tl(mMap.get_x_tl()+remove_pix);
				}
			}

		}
	}
	if (key==sf::Keyboard::D && b)
	{
		if (!(Collision()==C_RIGHT) && !(Collision()==C_TOP_RIGHT) && !(Collision()==C_BOTTOM_RIGHT))
		{
			if (-mMap.get_x_tl()+WIDTH>=mMap.get_m_largeur())
			{
				x+=v;
			}
			else
			{
				if (-mMap.get_x_tl()<=0)
				{
					if (x<=WIDTH/2)
					{
						x+=v;
					}
					else
					{
						mMap.set_x_tl(mMap.get_x_tl()-v);
					}
				}
				else
				{
					mMap.set_x_tl(mMap.get_x_tl()-v);
				}
			}

		}
		if (name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER,-mMap.get_y_tl()+y)) || name_to_obstacle(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER,-mMap.get_y_tl()+y+HEIGHT_CHARACTER)))
		{
			int remove_pix=-v;
			if (-mMap.get_x_tl()+WIDTH>=mMap.get_m_largeur())
			{
				x+=remove_pix;
			}
			else
			{
				if (-mMap.get_x_tl()<=0)
				{
					if (x<=WIDTH/2)
					{
						x+=remove_pix;
					}
					else
					{
						mMap.set_x_tl(mMap.get_x_tl()-remove_pix);
					}
				}
				else
				{
					mMap.set_x_tl(mMap.get_x_tl()-remove_pix);
				}
			}
		}
	}
	if (key==sf::Keyboard::Return && b)
	{
		mWindow.close();
	}
}





// Need to design a "COLLISION_TYPE collision_problem(mCharacter, mMap)" like function

COLLISION Character::Collision()
{
	
	if (y<=0 && x<=0)
	{
		return C_TOP_LEFT;
	}
	if (y<=0 && x+WIDTH_CHARACTER>=WIDTH)
	{
		return C_TOP_RIGHT;
	}
	if (y+HEIGHT_CHARACTER>=HEIGHT && x<=0)
	{
		return C_BOTTOM_LEFT;
	}
	if (y+HEIGHT_CHARACTER>=HEIGHT && x+WIDTH_CHARACTER>=WIDTH)
	{
		return C_BOTTOM_RIGHT;
	}
	if (y<=0)
	{
		return C_TOP;
	}
	if (y+HEIGHT_CHARACTER>=HEIGHT)
	{
		return C_BOTTOM;
	}
	if (x<=0)
	{
		return C_LEFT;
	}
	if (x+WIDTH_CHARACTER>=WIDTH)
	{
		return C_RIGHT;
	}
	return C_NONE;
}

void Character::character_data(sf::Keyboard::Key key, bool b)
{

	if (name_to_change_velocity(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER/2, -mMap.get_y_tl()+y) ))
	{
		v=name_to_new_velocity(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER/2, -mMap.get_y_tl()+y));
	}
	else
	{
		v=10;
	}
	if (name_to_change_level(mMap.get_elem_by_in_game_coordinates(-mMap.get_x_tl()+x+WIDTH_CHARACTER/2, -mMap.get_y_tl()+y)))
	{
		int current_x_tl = -mMap.get_x_tl();
		int current_y_tl = -mMap.get_y_tl();
		int current_x = get_x();
		int current_y = get_y();
		x=name_to_x(mMap.get_elem_by_in_game_coordinates(current_x_tl+current_x+WIDTH_CHARACTER/2, current_y_tl+current_y));
		y=name_to_y(mMap.get_elem_by_in_game_coordinates(current_x_tl+current_x+WIDTH_CHARACTER/2, current_y_tl+current_y))+30;
		mMap.reset_filename(name_to_adress_of_other_level(mMap.get_elem_by_in_game_coordinates(current_x_tl+current_x+WIDTH_CHARACTER/2, current_y_tl+current_y)),name_to_x_tl(mMap.get_elem_by_in_game_coordinates(current_x_tl+current_x+WIDTH_CHARACTER/2, current_y_tl+current_y)),name_to_y_tl(mMap.get_elem_by_in_game_coordinates(current_x_tl+current_x+WIDTH_CHARACTER/2, current_y_tl+current_y)));
		mCurrent_position=FRONT4;

		// 1) Améliorer le système de déplacement et faire des vrais pas - Là c'est un peu honteux.
		// 2) et surtout DOCUMENTER
		// Idéalement il faudrait commencer par documenter, c'est le plus essentiel si je veux
		// Repiger quelque chose quand je recommencerai vraiment à coder dans quelques semaines inchALLAH
	}
	if (key==sf::Keyboard::Q)
	{
		if (b && !(was_just_typing_front))
		{
			clock_front.restart();
			mCurrent_position=LEFT4;
		}
		if (!b)
		{
			mCurrent_position=LEFT4;
			was_just_typing_front=false;
		}
		else
		{
			was_just_typing_front=true;
		}
		if (was_just_typing_front==true && b)
		{

			if( ((clock_front.getElapsedTime()).asSeconds() <  1.000) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.900))
			{
			mCurrent_position=LEFT3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.900) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.800))
			{
			mCurrent_position=LEFT2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.800) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.700))
			{
			mCurrent_position=LEFT1;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.700) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.600))
			{
			mCurrent_position=LEFT2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.600) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.500))
			{
			mCurrent_position=LEFT3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.500) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.400))
			{
			mCurrent_position=LEFT5;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.400) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.300))
			{
			mCurrent_position=LEFT6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.300) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.200))
			{
			mCurrent_position=LEFT7;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.200) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.100))
			{
			mCurrent_position=LEFT6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.100) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.000))
			{
			mCurrent_position=LEFT5;
			}
			if ((clock_front.getElapsedTime()).asSeconds() >=  1.000)
			{
				clock_front.restart();
				mCurrent_position=LEFT4;
			}
		}
	}
	if (key==sf::Keyboard::D)
	{
		if (b && !(was_just_typing_front))
		{
			clock_front.restart();
			mCurrent_position=RIGHT4;
		}
		if (!b)
		{
			mCurrent_position=RIGHT4;
			was_just_typing_front=false;
		}
		else
		{
			was_just_typing_front=true;
		}
		if (was_just_typing_front==true && b)
		{

			if( ((clock_front.getElapsedTime()).asSeconds() <  1.000) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.900))
			{
			mCurrent_position=RIGHT3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.900) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.800))
			{
			mCurrent_position=RIGHT2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.800) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.700))
			{
			mCurrent_position=RIGHT1;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.700) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.600))
			{
			mCurrent_position=RIGHT2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.600) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.500))
			{
			mCurrent_position=RIGHT3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.500) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.400))
			{
			mCurrent_position=RIGHT5;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.400) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.300))
			{
			mCurrent_position=RIGHT6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.300) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.200))
			{
			mCurrent_position=RIGHT7;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.200) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.100))
			{
			mCurrent_position=RIGHT6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.100) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.000))
			{
			mCurrent_position=RIGHT5;
			}
			if ((clock_front.getElapsedTime()).asSeconds() >=  1.000)
			{
				clock_front.restart();
				mCurrent_position=RIGHT4;
			}
		}
	}
	if (key==sf::Keyboard::S)
	{
		if (b && !(was_just_typing_front))
		{
			clock_front.restart();
			mCurrent_position=FRONT4;
		}
		if (!b)
		{
			mCurrent_position=FRONT4;
			was_just_typing_front=false;
		}
		else
		{
			was_just_typing_front=true;
		}
		if (was_just_typing_front==true && b)
		{

			if( ((clock_front.getElapsedTime()).asSeconds() <  1.000) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.900))
			{
			mCurrent_position=FRONT3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.900) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.800))
			{
			mCurrent_position=FRONT2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.800) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.700))
			{
			mCurrent_position=FRONT1;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.700) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.600))
			{
			mCurrent_position=FRONT2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.600) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.500))
			{
			mCurrent_position=FRONT3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.500) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.400))
			{
			mCurrent_position=FRONT5;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.400) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.300))
			{
			mCurrent_position=FRONT6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.300) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.200))
			{
			mCurrent_position=FRONT7;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.200) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.100))
			{
			mCurrent_position=FRONT6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.100) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.000))
			{
			mCurrent_position=FRONT5;
			}
			if ((clock_front.getElapsedTime()).asSeconds() >=  1.000)
			{
				clock_front.restart();
				mCurrent_position=FRONT4;
			}
		}
	}
	if (key==sf::Keyboard::Z)
	{
		
		if (b && !(was_just_typing_back))
		{
			clock_front.restart();
			mCurrent_position=BACK4;
		}
		if (!b)
		{
			mCurrent_position=BACK4;
			was_just_typing_back=false;
		}
		else
		{
			was_just_typing_back=true;
		}
		if (was_just_typing_back==true && b)
		{

			if( ((clock_front.getElapsedTime()).asSeconds() <  1.000) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.900))
			{
			mCurrent_position=BACK3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.900) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.800))
			{
			mCurrent_position=BACK2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.800) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.700))
			{
			mCurrent_position=BACK1;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.700) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.600))
			{
			mCurrent_position=BACK2;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.600) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.500))
			{
			mCurrent_position=BACK3;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.500) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.400))
			{
			mCurrent_position=BACK5;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.400) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.300))
			{
			mCurrent_position=BACK6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.300) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.200))
			{
			mCurrent_position=BACK7;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.200) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.100))
			{
			mCurrent_position=BACK6;
			}
			if( ((clock_front.getElapsedTime()).asSeconds() <  0.100) && ( (clock_front.getElapsedTime()).asSeconds() >= 0.000))
			{
			mCurrent_position=BACK5;
			}
			if ((clock_front.getElapsedTime()).asSeconds() >=  1.000)
			{
				clock_front.restart();
				mCurrent_position=BACK4;
			}
		}
	}
}

void Character::set_x(int new_x)
{
	x=new_x;
}
void Character::set_y(int new_y)
{
	y=new_y;
}