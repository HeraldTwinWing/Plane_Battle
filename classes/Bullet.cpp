//
// Created by Avalanche_Exia on 2019/4/6.
//


#include "Bullet.h"


void Bullet::move()
{
	double timeLength = 0.001 * (SDL_GetTicks() - lastMove);

	//std::cout << "TL:" << timeLength << std::endl;

	moveTemp.first += speed * timeLength * std::cos(direction_theta * 3.14);
	moveTemp.second += speed * timeLength * std::sin(direction_theta * 3.14);

	if (std::abs(moveTemp.first) > 1)
	{
		position.x += (int) std::trunc(moveTemp.first);
		moveTemp.first -= std::trunc(moveTemp.first);
	}

	if (std::abs(moveTemp.second) > 1)
	{
		position.y += (int) std::trunc(moveTemp.second);
		moveTemp.second -= std::trunc(moveTemp.second);
	}
	lastMove = SDL_GetTicks();
}

void Bullet::showImage()
{

	SDL_RenderCopyEx(window->getRenderer(), texture, nullptr, &position, direction_theta * 180, nullptr, SDL_FLIP_NONE);
}

Bullet::Bullet(int atk, int speed, double direction_theta, Window *window, SDL_Point position,
               SDL_Texture *texture)
{
	lastMove = SDL_GetTicks();
	this->atk = atk;
	this->speed = speed;
	this->direction_theta = direction_theta;
	this->window = window;
	this->texture = texture;

	this->position.x = position.x;
	this->position.y = position.y;
	SDL_QueryTexture(texture, nullptr, nullptr, &this->position.w, &this->position.h);

	//std::cout << "[new bullet]" << "x: " << position.x << " y: " << position.y << std::endl;
}

Bullet::~Bullet() = default;
