#pragma once

#include <utility>
#include <string>
#include <array>
#include "Plane.h"

enum EnemyMoveMode
{
	LINE, SIN, PARABOLA, CIRCLE
};

class Enemy :
		public Plane
{
public:
	double lastMove;
	double parameter;
	double sinMoveTemp;
	std::pair<double, double> MoveTemp;

	SDL_Rect originPosition;
	double lineMoveDirection;
	int sinMoveAmplitude;
	double sinMovePeriod;
	double parabolaMoveA;
	double parabolaMoveB;
	double parabolaMoveC;
	SDL_Point circleMoveCenter;
	int circleMoveRadius;
	std::array<bool, 4> *moveMode;
	double spawntime;

	Enemy() = default;

	Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
	      const std::string &texture_name, Window *window, int sinMoveAmplitude, double sinMovePeriod,
	      double parabolaMoveA, double parabolaMoveB, double parabolaMoveC, SDL_Point circleMoveCenter,
	      int circleMoveRadius, std::array<bool, 4> *moveMode);

	Enemy(HitBox *hitbox, Window *window, Save save);

	void spawn() override;

	void move() override;

	void fire(std::deque<Bullet> &enemyBullets) override ;

	//刷新状态及贴图
	void refresh() override;

	void showImage() override;

	// y轴方向上周期运动
	void MoveAsSin();

	void MoveAsParabola();

	void MoveAsCircle();

	//直线移动
	//参数为极坐标下θ,单位为Π
	void MoveAsLine();

	~Enemy();
};