#pragma once
#include "Plane.h"

enum MoveMode{LINE, SNAKE_SKIN, CIRCLE, };

class Enemy :
	public Plane
{
public:

	Enemy();

    void move();
	void move_as_sin(int direction);
	void move_as_parabola(int direction);
	void move_as_circle(int direction);
    void move_as_line(int direction);

	~Enemy();
};

