#include "Plane.h"


Plane::Plane(int max_health, int speed, HitBox hitbox, int coordinate_x, int coordinate_y, std::string texture_name)
{

}

Plane::Plane(int max_health, int speed, HitBox hitbox, std::string texture_name)
{

}

Plane::Plane(Plane &plane)
{

}

bool Plane::damage(int damage_amount)
{
    return false;
}

void Plane::spawn()
{
}

void Plane::move(SDL_Event &key)
{
}

void Plane::change_weapon(std::string weapon_category)
{
}

void Plane::shoot()
{
}





