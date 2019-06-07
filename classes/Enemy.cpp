#include <utility>

#include "Enemy.h"


Enemy::Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window)
		: Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
{
	lastMove = SDL_GetTicks();
	parameter = 0;
	originPosition = position;
	lastMove = SDL_GetTicks();
	sinMoveTemp = 0;

	weapon = new Weapon(1,0.5,false);
}

Enemy::Enemy(HitBox *hitbox , Window *window,Save save)//:Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
		: Plane(hitbox, window, std::move(save))
{
	lastMove = SDL_GetTicks();
	parameter = 0;
	originPosition = position;
	lastMove = SDL_GetTicks();
	sinMoveTemp = 0;

	weapon = new Weapon(1,0.5,false);
	//std::cout<<this->maxHealth<< this->health<<this->speed<<this->position.x<<this->position.y<<std::endl;
}

Enemy::~Enemy() = default;

void Enemy::move()
{
	//MoveAsSin();
	//MoveAsLine(0);
	lastMove = SDL_GetTicks();
}

void Enemy::refresh()
{
	move();

	hitbox->center_x = position.x;
	hitbox->center_y = position.y;

	//std::cout << "x:" << position.x << "  y: " << position.y << std::endl;
    //std::cout << "x:" << hitbox->center_x << "  y: " << hitbox->center_y  << std::endl;
	SDL_RenderCopy(window->getRenderer(), texture, nullptr, &position);
}

void Enemy::spawn()
{
	SDL_RenderCopy(window->getRenderer(), texture, nullptr, &position);
}

void Enemy::MoveAsSin(int amplitude, double period)
{
	double timeLength = SDL_GetTicks() - lastMove;

	double angularVelocity = 2 * 3.14 / period;

	sinMoveTemp = amplitude * std::sin(angularVelocity * 0.001 * SDL_GetTicks());
	//std::cout << "sinMoveTemp:" << sinMoveTemp << std::endl;

	if (sinMoveTemp > 0)
	{
		position.y = std::floor(originPosition.y + sinMoveTemp);
	}
	else
	{
		position.y = std::ceil(originPosition.y + sinMoveTemp);
	}

	//≤‚ ‘¥˙¬Î
	//std::cout << "time:" << timeLength << std::endl;

	parameter += timeLength;

	//≤‚ ‘¥˙¬Î
	//std::cout << "t:" << parameter << std::endl;
}

void Enemy::MoveAsSin()
{
	MoveAsSin(200, 5);
}

void Enemy::MoveAsLine(double direction)
{
	double timeLength = 0.001 * (SDL_GetTicks() - lastMove);

	//std::cout << "TL:" << timeLength << std::endl;

	lineMoveTemp.first += speed * timeLength * std::cos(direction * 3.14);
	lineMoveTemp.second += speed * timeLength * std::sin(direction * 3.14);

	if (std::abs(lineMoveTemp.first) > 1)
	{
		position.x += (int) std::trunc(lineMoveTemp.first);
		originPosition.x += (int) std::trunc(lineMoveTemp.first);
		lineMoveTemp.first -= std::trunc(lineMoveTemp.first);
	}

	if (std::abs(lineMoveTemp.second) > 1)
	{
		position.y += (int) std::trunc(lineMoveTemp.second);
		originPosition.y += (int) std::trunc(lineMoveTemp.second);
		lineMoveTemp.second -= std::trunc(lineMoveTemp.second);
	}
}

void Enemy::MoveAsLine()
{
	MoveAsLine(0);
}

void Enemy::MoveAsParabola(double a, double v, double c)
{

}