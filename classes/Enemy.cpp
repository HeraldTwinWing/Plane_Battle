#include "Enemy.h"

Enemy::Enemy(HitBox *hitbox, Window *window,
             Save &save)//:Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
		: Plane(hitbox, window, save)
{
	lastMove = SDL_GetTicks();
	parameter = 0;
	originPosition = position;
	sinMoveTemp = 0;
	this->spawntime = save.spawnTime;
	this->sinMoveAmplitude = save.planeInfo["sinMoveAmplitude"];
	this->sinMovePeriod = save.planeInfo["sinMovePeriod"];
	this->parabolaMoveA = save.planeInfo["parabolaMoveA"];
	this->parabolaMoveB = save.planeInfo["parabolaMoveB"];
	this->parabolaMoveC = save.planeInfo["parabolaMoveC"];
	this->circleMoveCenter.x = save.planeInfo["circleMoveCenter_x"];
	this->circleMoveCenter.y = save.planeInfo["circleMoveCenter_y"];
	this->circleMoveRadius = save.planeInfo["circleMoveRadius"];
	this->moveMode = new std::array<bool, 4>(save.movemode);
//	this->width = save.planeInfo["Width"];
//	this->height = save.planeInfo["Height"];
	SDL_QueryTexture(texture, nullptr, nullptr,&position.w,&position.h);
			weapon = new Weapon(1, 0.5, false);

	weapon = new Weapon(0, 0.5, false);
	weapon->category = ENEMYBULLET;
	firing = true;
	fireOriginPosition.x = position.x;
	fireOriginPosition.y = position.y + position.w / 2;
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

	hitbox->set_x(position.x + position.w / 2);
	hitbox->set_y(position.y + position.h / 2);
	fireOriginPosition.x = position.x - 20;
	fireOriginPosition.y = position.y + position.w / 2;


	//std::cout << "x:" << position.x << "  y: " << position.y << std::endl;
	//std::cout << "x:" << hitbox->center_x << "  y: " << hitbox->center_y << std::endl;
	SDL_RenderCopyEx(window->getRenderer(), texture, nullptr, &position, lineMoveDirection * 180, nullptr,
	                 SDL_FLIP_NONE);
}

void Enemy::spawn()
{
	SDL_RenderCopyEx(window->getRenderer(), texture, nullptr, &position, lineMoveDirection * 180, nullptr,
	                 SDL_FLIP_NONE);
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

	//std::cout << "time:" << timeLength << std::endl;

	parameter += timeLength;

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

void Enemy::showImage()
{
	SDL_RenderCopyEx(window->getRenderer(), texture, nullptr, &position, std::trunc(lineMoveDirection * 180), nullptr,
	                 SDL_FLIP_NONE);
}

void Enemy::fire(std::deque<Bullet> &enemyBullets)
{
	lastFire = SDL_GetTicks();
	enemyBullets.push_back(weapon->fire(window, window->loadPicture("enemyBullet.png"), &fireOriginPosition));
	std::cout << "fire at: " << SDL_GetTicks() << std::endl;
}

bool Enemy::if_not_in_fire_CD()
{
	return (SDL_GetTicks() - lastFire) / 1000 > weapon->fireInterval;
}
