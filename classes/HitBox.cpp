#include "HitBox.h"


HitBox::HitBox(std::string category)
{
    if (category == "square")
        this->category = square;
    else
        this->category = circle;
}


HitBox::~HitBox()
{
}

bool HitBox::hit(weapon_category_list weapon_category)
{
    return false;
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
