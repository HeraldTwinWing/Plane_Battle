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
	SDL_Rect clip;
	clip.x = 0;
	clip.y = 0;
	clip.w = 11;
	clip.h = 38;

	position.w = 11;
	position.h = 38;
	SDL_RenderCopyEx(window->get_renderer(), texture, &clip, &position, 90, nullptr, SDL_FLIP_NONE);
}

Bullet::Bullet(int atk, int speed, double direction_theta, Window *window, SDL_Rect position,
               SDL_Texture *texture)
{
	this->atk = atk;
	this->speed = speed;
	this->direction_theta = direction_theta;
	this->window = window;
	this->texture = texture;

	this->position.x = position.x + 158;
	this->position.y = position.y + 102;
}
