#pragma once
#include "Plane.h"


class Enemy :
	public Plane
{
public:
    double lastMove;
    double parameter;
    double temp;

    SDL_Rect originPostion;

    Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
		  const std::string &texture_name, Window *window);

	void spawn() override;
    void move() override;
    void refresh() override;
	void move_as_sin();
	void move_as_parabola(int direction);
	void move_as_circle(int direction);
    void move_as_line(int direction);

	~Enemy();
};