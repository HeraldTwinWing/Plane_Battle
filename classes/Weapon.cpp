#include "Weapon.h"
#include "Bullet.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

Bullet Weapon::fire(Window* target_window,SDL_Texture* texture, SDL_Rect *position)
{
	switch (category)
	{
		case bullet:
			return {15, 8, 0, target_window, *position, texture};
			break;
		case pellet:
			break;
		case beam:
			break;
	}
}

Weapon::Weapon(weapon_category_list weapon_category)
{
	this->category = weapon_category;

	switch (weapon_category)
	{
		case beam:
			this->fire_interval = 0.1;
			break;
		case bullet:
			this->fire_interval = 0.3;
			break;
		case pellet:
			std::cout << "Called the wrong method" << std::endl;
			break;
	}
}


