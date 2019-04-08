#pragma once
#include "Plane.h"


class Enemy :
	public Plane
{
private:

public:
	Enemy();

    void move();
	void move_as_sin(int direction);
	void move_as_parabola(int direction);
	void move_as_circle(int direction);
    void move_as_line(int direction);

	~Enemy();
};

