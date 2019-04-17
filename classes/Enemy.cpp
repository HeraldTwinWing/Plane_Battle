#include "Enemy.h"


Enemy::Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window)
        : Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
{
}


Enemy::~Enemy()
{
}

void Enemy::move()
{

}

void Enemy::refresh()
{
    move();
    hitbox->center_x = position.x;
    hitbox->center_y = position.y;
    SDL_RenderCopy(window->get_renderer(), texture, nullptr, &position);
}

void Enemy::spawn()
{
    SDL_RenderCopy(window->get_renderer(),texture, nullptr,&position);
}
