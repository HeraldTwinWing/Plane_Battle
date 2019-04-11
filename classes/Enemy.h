#pragma once
#include "Plane.h"

enum MoveMode{LINE, SNAKE_SKIN, CIRCLE, };

class Enemy :
	public Plane
{
public:

	Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
		  const std::string &texture_name, Window *window);

    void move();
	void move_as_sin(int direction);
	void move_as_parabola(int direction);
	void move_as_circle(int direction);
    void move_as_line(int direction);

	~Enemy();
};

