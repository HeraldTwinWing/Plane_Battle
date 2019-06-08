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
    //�ӵ����з���,�Լ�����Ƕȱ��,��Ϊ������,��λΪpi*rad
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
