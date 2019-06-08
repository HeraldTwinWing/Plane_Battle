#include <utility>

#include "Weapon.h"
#include "Bullet.h"


Weapon::Weapon(std::vector<double> directions, double fire_interval, bool aim)
{
    this->directions = std::move(directions);
    this->fireInterval = fire_interval;
    this->aim = aim;
    this->category = BULLET;
}

Weapon::Weapon(int direction, double fire_interval, bool aim)
{
	this->direction = direction;
	this->fireInterval = fire_interval;
	this->aim = aim;
	this->category = BULLET;
}

Weapon::~Weapon() = default;

Bullet Weapon::fire(Window* target_window, SDL_Texture* texture, SDL_Point* position)
{
	if (count >= directions.size())
		count = 0;
    switch (category)
    {
        case BULLET:
            return {15, 1200, 0, target_window, *position, texture};
            break;
        case ENEMYBULLET:
	        return {15, 300, directions[count++], target_window, *position, texture};
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
            this->fireInterval = 0.2;
            break;
        case BULLET:
            this->fireInterval = 0.2;
            break;
        case ENEMYBULLET:
            std::cout << "Called the wrong method" << std::endl;
            break;
    }
}


