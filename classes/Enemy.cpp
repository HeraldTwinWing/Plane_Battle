#include "Enemy.h"


Enemy::Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window)
        : Plane(max_health, speed, hitbox, coordinate_x, coordinate_y, texture_name, window)
{
    double lastMove = 0;
    double parameter = 0;
    double temp = 0;
    originPostion = position;
}


Enemy::~Enemy()
{
}

void Enemy::move()
{

}

void Enemy::refresh()
{
    //move();
    move_as_sin();

    hitbox->center_x = position.x;
    hitbox->center_y = position.y;
    SDL_RenderCopy(window->get_renderer(), texture, nullptr, &position);
}

void Enemy::spawn()
{
    SDL_RenderCopy(window->get_renderer(), texture, nullptr, &position);
}

void Enemy::move_as_sin()
{
    double timeLength = (SDL_GetTicks() - lastMove) / 1000;

//    if (timeLength > 1)
//    {
//        timeLength = 0;
//    }

    temp = 200 * std::sin(2*  0.001 *  SDL_GetTicks());
    std::cout << "temp:" << temp << std::endl;

    if ( temp > 0 )
    {
        position.y = std::floor(originPostion.y + temp);
    }
    else
    {
        position.y = std::ceil(originPostion.y + temp);
    }

    std::cout << "time:" << timeLength << std::endl;

    parameter += timeLength;
//    if ( parameter > 3.14 * 2 )
//    {
//        parameter = 0;
//    }

    std::cout << "t:" << parameter << std::endl;
}
