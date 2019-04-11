#include <utility>

#include "HitBox.h"
#include <cmath>


HitBox::HitBox(std::string category)
{
    this->category = std::move(category);
}


HitBox::~HitBox()
{
}

bool HitBox::ifBulletHit(Bullet *bullet)
{
    if ( category == "square" )
    {
        return bullet->position.x < center_x + radius && bullet->position.x > center_x - radius
               && bullet->position.y < center_y + radius && bullet->position.y > center_y - radius;

    }
    else if ( category == "circle" )
    {
        return std::pow(bullet->position.x - center_x, 2) + std::pow(bullet->position.x - center_y, 2)
               < std::pow(radius, 2);
    }
}

bool HitBox::square_hitbox_hit_by_bullet()
{
    return false;
}

bool HitBox::square_hitbox_hit_by_beam()
{
    return false;
}

bool HitBox::circle_hitbox_hit_by_bullet()
{

    return false;
}

bool HitBox::circle_hitbox_hit_by_beam()
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
