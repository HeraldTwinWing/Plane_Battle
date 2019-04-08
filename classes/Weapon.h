#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include "Window.h"
#include "Bullet.h"

enum weapon_category_list
{
    pellet, bullet, beam
};

class Weapon
{
private:
	double fire_interval;
	weapon_category_list category;
public:
    Weapon();
    Weapon(weapon_category_list weapon_category);

	weapon_category_list get_weapon_category()
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