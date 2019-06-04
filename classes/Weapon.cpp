#include <utility>

#include "Weapon.h"
#include "Bullet.h"


Weapon::Weapon(std::vector<int> directions, double fire_interval, bool aim)
{
    this->directions = std::move(directions);
    this->fire_interval = fire_interval;
    this->aim = aim;
    this->category = BULLET;
}

Weapon::~Weapon() = default;

Bullet Weapon::fire(Window* target_window, SDL_Texture* texture, SDL_Point* position)
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


