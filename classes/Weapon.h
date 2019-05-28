#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <vector>
#include "Bullet.h"

enum WeaponCategoryEnum
{
    PELLET, BULLET, BEAM
};

class Weapon
{
private:
	double fire_interval;

	//开火时瞄准玩家
	bool aim = false;
	//敌方单位子弹的方向
	std::vector<int> directions;
	WeaponCategoryEnum category;
public:
    Weapon(std::vector<int> directions, double fire_interval, bool aim);
    explicit Weapon(WeaponCategoryEnum weapon_category);

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