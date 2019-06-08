#pragma once

#include <utility>
#include <string>
#include <vector>
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
	std::vector<EnemyMoveMode> *moveMode;

	Enemy() = default;

	Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
	      const std::string &texture_name, Window *window, int sinMoveAmplitude, double sinMovePeriod,
	      double parabolaMoveA, double parabolaMoveB, double parabolaMoveC, SDL_Point circleMoveCenter,
	      int circleMoveRadius, std::vector<EnemyMoveMode> *moveMode);

	void spawn() override;

	void move() override;

	//ˢ��״̬����ͼ
	void refresh() override;

	// y�᷽���������˶�
	void MoveAsSin();

	void MoveAsParabola();

	void MoveAsCircle();

	//ֱ���ƶ�
	//����Ϊ�������¦�,��λΪ��
	void MoveAsLine();

	~Enemy();
};