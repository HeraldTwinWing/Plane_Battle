#include "Weapon.h"
#include "Bullet.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()=default;

Bullet Weapon::fire(Window* target_window,SDL_Texture* texture, SDL_Rect *position)
{
	switch (category)
	{
		case BULLET:
			return {15, 8, 0, target_window, *position, texture};
			break;
		case PELLET:
			break;
		case BEAM:
			break;
	}
}

Weapon::Weapon(WeaponCategoryEnum weapon_category)
{
	this->category = weapon_category;

	switch (weapon_category)
	{
		case BEAM:
			this->fire_interval = 0.1;
			break;
		case BULLET:
			this->fire_interval = 0.1;
			break;
		case PELLET:
			std::cout << "Called the wrong method" << std::endl;
			break;
	}
}


