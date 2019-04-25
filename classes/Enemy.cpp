#include "Enemy.h"


Enemy::Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window)
		: Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
{
}


Enemy::~Enemy()
{
}

void Enemy::move()
{

}

void Enemy::refresh()
{
	//move();
	move_as_sin();

	hitbox->center_x = position.x;
	hitbox->center_y = position.y;
	SDL_RenderCopy(window->get_renderer(), texture, nullptr, &position);
}

void Enemy::spawn()
{+
	SDL_RenderCopy(window->get_renderer(), texture, nullptr, &position);
}

void Enemy::move_as_sin()
{
	static double lastMove;
	static double parameter;
	static double temp;

	position.y += std::lround( 5*std::cos(parameter * speed) );
	temp = std::sin(parameter) * speed - std::lround(std::sin(parameter) * speed);
	if (std::trunc(temp) > 0)
	{
		position.y += std::lround(temp);
		temp -= lround(temp);
	}

	std::cout << (SDL_GetTicks() - lastMove)/1000 << std::endl;
	lastMove = SDL_GetTicks();

	parameter += 0.1;

	if (parameter > 3.14 * 2)
	{
		parameter = 0;
	}
}
