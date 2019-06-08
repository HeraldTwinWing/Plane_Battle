//
// Created by Avalanche_Exia on 2019/4/6.
//

#ifndef PLANE_BATTLE_BULLET_H
#define PLANE_BATTLE_BULLET_H

#include <SDL2/SDL.h>
#include <cmath>
#include "Window.h"

class Bullet
{
public:
    int atk;
    int speed;
    double pi = std::acos(-1);
    //子弹飞行方向,以极坐标角度标记,右为正方向,单位为pi*rad
    double direction_theta;
    Window *window;
    SDL_Rect position{};
    SDL_Texture *texture;


    Bullet(int atk, int speed, double direction_theta, Window *window, SDL_Point position,
             SDL_Texture *texture);

    ~Bullet();

    int getAtk()
    {
        return atk;
    }

    void move();

    void showImage();
};

#endif //PLANE_BATTLE_BULLET_H
