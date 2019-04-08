//
// Created by Avalanche_Exia on 2019/4/6.
//

#ifndef PLANE_BATTLE_BULLET_H
#define PLANE_BATTLE_BULLET_H

#include <SDL2/SDL.h>
#include <cmath>
#include "Weapon.h"
#include "Window.h"

class Bullet
{
private:
	int atk;
	int speed;
	const double pi = std::acos(-1);
	//子弹飞行方向,以极坐标角度标记,右为正方向,单位为pi*rad
	double direction_theta;
	Window *window;
	SDL_Rect position{};
	SDL_Texture *texture;
public:

	Bullet(int atk, int speed, double direction_theta, Window *window, SDL_Rect position,
	       SDL_Texture *texture) : atk, speed, direction_theta, window, position, texture;

	int get_atk()
	{
		return atk;
	}

	void move();

	void show_image();
};


#endif //PLANE_BATTLE_BULLET_H
