#include <utility>

#include "HitBox.h"
#include <cmath>


HitBox::HitBox(hitbox_category  category)
{
    this->category = category;
}


HitBox::~HitBox()
{
}

bool HitBox::hit(weapon_category_list weapon_category, Bullet *bullet)
{

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

