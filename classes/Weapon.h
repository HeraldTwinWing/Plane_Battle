#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <vector>
#include "Bullet.h"

enum WeaponCategoryEnum
{
	ENEMYBULLET, BULLET, BEAM
};

class Weapon
{
public:
	double fireInterval;
	int count = 0;

	//开火时瞄准玩家
	bool aim = false;
	//敌方单位子弹的方向
	std::vector<double> directions = {0.9, 0.95, 1, 1.05, 1.1, 1.05, 1, 0.95};
	int direction;
	WeaponCategoryEnum category;

	Weapon(std::vector<double> directions, double fire_interval, bool aim);

	Weapon(int direction, double fire_interval, bool aim);

	explicit Weapon(WeaponCategoryEnum weapon_category);

	WeaponCategoryEnum get_weapon_category()
	{
		return category;
	}

	Bullet fire(Window *target_window, SDL_Texture *texture, SDL_Point *position);

	double get_fire_interval()
	{
		return fireInterval;
	}

	~Weapon();
};