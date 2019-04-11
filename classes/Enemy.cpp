#include "Enemy.h"



Enemy::Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window)
{
    this->max_health = max_health;
    this->health = max_health;
    this->speed = speed;
    this->hitbox = hitbox;
    this->position.x = coordinate_x;
    this->position.y = coordinate_y;
    this->texture = window->load_picture(texture_name);
    this->window = window;
    this->firing = false;
    this->last_fire = SDL_GetTicks();
}


Enemy::~Enemy()
{
}
