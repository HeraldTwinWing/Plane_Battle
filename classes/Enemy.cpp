#include "Enemy.h"

Enemy::Enemy(HitBox *hitbox, Window *window,
             Save save)//:Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
		: Plane(hitbox, window, std::move(save))
{
	lastMove = SDL_GetTicks();
	parameter = 0;
	originPosition = position;
	lastMove = SDL_GetTicks();
	sinMoveTemp = 0;

	weapon = new Weapon(1, 0.5, false);
	//std::cout<<this->maxHealth<< this->health<<this->speed<<this->position.x<<this->position.y<<std::endl;
}


Enemy::Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window, int sinMoveAmplitude, double sinMovePeriod,
             double parabolaMoveA, double parabolaMoveB, double parabolaMoveC, SDL_Point circleMoveCenter,
             int circleMoveRadius, std::array<bool, 4> *moveMode)
		: Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
{
	lastMove = SDL_GetTicks();
	parameter = 0;
	originPosition = position;
	lastMove = SDL_GetTicks();
	sinMoveTemp = 0;

	this->sinMoveAmplitude = sinMoveAmplitude;
	this->sinMovePeriod = sinMovePeriod;
	this->parabolaMoveA = parabolaMoveA;
	this->parabolaMoveB = parabolaMoveB;
	this->parabolaMoveC = parabolaMoveC;
	this->circleMoveCenter = circleMoveCenter;
	this->circleMoveRadius = circleMoveRadius;
	this->moveMode = moveMode;

	weapon = new Weapon(1, 0.5, false);
}


Enemy::~Enemy() = default;

void Enemy::move()
{
	if (moveMode->at(0))
		MoveAsLine();
	if (moveMode->at(1))
		MoveAsSin();
	if (moveMode->at(2))
		MoveAsParabola();
	if (moveMode->at(3))
		MoveAsCircle();
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

void Enemy::MoveAsSin()
{
	double timeLength = SDL_GetTicks() - lastMove;

	double angularVelocity = 2 * 3.14 / sinMovePeriod;

	sinMoveTemp = sinMoveAmplitude * std::sin(angularVelocity * 0.001 * SDL_GetTicks());
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


void Enemy::MoveAsLine()
{
	double timeLength = 0.001 * (SDL_GetTicks() - lastMove);

	//std::cout << "TL:" << timeLength << std::endl;

	MoveTemp.first += speed * timeLength * std::cos(lineMoveDirection * 3.14);
	MoveTemp.second += speed * timeLength * std::sin(lineMoveDirection * 3.14);

	if (std::abs(MoveTemp.first) > 1)
	{
		position.x += (int) std::trunc(MoveTemp.first);
		originPosition.x += (int) std::trunc(MoveTemp.first);
		MoveTemp.first -= std::trunc(MoveTemp.first);
	}

	if (std::abs(MoveTemp.second) > 1)
	{
		position.y += (int) std::trunc(MoveTemp.second);
		originPosition.y += (int) std::trunc(MoveTemp.second);
		MoveTemp.second -= std::trunc(MoveTemp.second);
	}
}


void Enemy::MoveAsParabola()
{

}

void Enemy::MoveAsCircle()
{

}
