#include <utility>

#include "HitBox.h"
#include <cmath>


HitBox::HitBox(hitbox_category  category, int radius)
{
    this->category = category;
    this->radius = radius;
}


HitBox::~HitBox()
{
}

bool HitBox::hit(weapon_category_list weapon_category, Bullet *bullet)
{
    return false;
}

bool HitBox::ifBulletHit(Bullet *bullet)
{
    if ( category == SQUARE_HITBOX )
    {
        return bullet->position.x < center_x + radius && bullet->position.x > center_x - radius
               && bullet->position.y < center_y + radius && bullet->position.y > center_y - radius;

    }
    else if ( category == CIRCLE_HITBOX )
    {
        return std::pow(bullet->position.x - center_x, 2) + std::pow(bullet->position.x - center_y, 2)
               < std::pow(radius, 2);
    }
    return false;
}

bool HitBox::ifBeamHit()
{
	return false;
}


void HitBox::set_x(int x)
{
    center_x = x;
}

void HitBox::set_y(int y)
{
    center_y = y;
}

