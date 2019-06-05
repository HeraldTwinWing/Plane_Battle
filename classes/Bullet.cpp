//
// Created by Avalanche_Exia on 2019/4/6.
//


#include "Bullet.h"


void Bullet::move()
{
    position.x += std::floor(speed * cos(direction_theta * pi));
    position.y += std::floor(speed * sin(direction_theta * pi));
}

void Bullet::show_image()
{

    SDL_RenderCopyEx(window->getRenderer(), texture, nullptr, &position, direction_theta * 180, nullptr, SDL_FLIP_NONE);
}

Bullet::Bullet(int atk, int speed, double direction_theta, Window *window, SDL_Point position,
                 SDL_Texture *texture)
{
    this->atk = atk;
    this->speed = speed;
    this->direction_theta = direction_theta;
    this->window = window;
    this->texture = texture;

    this->position.x = position.x;
    this->position.y = position.y;
    SDL_QueryTexture(texture, nullptr, nullptr,&this->position.w,&this->position.h);

    //std::cout << "[new bullet]" << "x: " << position.x << " y: " << position.y << std::endl;
}

Bullet::~Bullet()=default;
