#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include "Bullet.h"

enum WeaponCategoryEnum
{
    PELLET, BULLET, BEAM
};

class Weapon
{
private:
	double fire_interval;
	WeaponCategoryEnum category;
public:
    Weapon();
    Weapon(WeaponCategoryEnum weapon_category);

	WeaponCategoryEnum get_weapon_category()
    {
        return category;
    }

    Bullet fire(Window* target_window, SDL_Texture* texture, SDL_Rect *position);

	double get_fire_interval()
    {
        return fire_interval;
    }
    ~Weapon();
};