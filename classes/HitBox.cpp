#include <utility>

#include "HitBox.h"
#include <cmath>


HitBox::HitBox(hitbox_category category, int radius)
{
    this->category = category;
    this->radius = radius;

    center_x = 0;
    center_y = 0;
}


HitBox::~HitBox()=default;
bool HitBox::hit(WeaponCategoryEnum weaponCategoryEnum, Bullet *bullet)
{
    switch (weaponCategoryEnum)
    {
        case BULLET:
            break;
    }
    return false;
}

bool HitBox::ifBulletHit(Bullet *bullet)
{
    if ( category == SQUARE_HITBOX )
    {
        return std::abs(bullet->position.x - center_x) < radius && std::abs(bullet->position.y - center_y) < radius;
    }
    else if ( category == CIRCLE_HITBOX )
    {
        return std::pow(bullet->position.x - center_x, 2) + std::pow(bullet->position.y - center_y, 2)
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

