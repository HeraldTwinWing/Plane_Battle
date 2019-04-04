#include "Plane.h"


Plane::Plane(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, SDL_Renderer *target_renderer)
{
    this->max_health = max_health;
    this->health = max_health;
    this->speed = speed;
    this->hitbox = hitbox;
    this->position.x = coordinate_x;
    this->position.y = coordinate_y;
    this->texture = load_picture(texture_name, target_renderer);
    this->target_renderer = target_renderer;

    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

Plane::Plane(int max_health, int speed, HitBox *hitbox,
             const std::string &texture_name, SDL_Renderer *target_renderer)
{
    this->max_health = max_health;
    this->health = max_health;
    this->speed = speed;
    this->hitbox = hitbox;
    this->position.x = SDL_WINDOWPOS_CENTERED;
    this->position.y = SDL_WINDOWPOS_CENTERED;
    this->texture = load_picture(texture_name, target_renderer);
    this->target_renderer = target_renderer;
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

Plane::Plane(Plane &plane)
{
}

bool Plane::damage(int damage_amount)
{
    health -= damage_amount;

    return health > 0;
}

void Plane::spawn()
{
    SDL_RenderClear(target_renderer);
    SDL_RenderCopy(target_renderer, texture, nullptr, &position);
    SDL_RenderPresent(target_renderer);
}

void Plane::move(SDL_Event &key)
{
    if (key.key.keysym.sym == SDLK_UP)
    {
        position.y -= speed;
    }
    if (key.key.keysym.sym == SDLK_DOWN)
    {
        position.y += speed;
    }
    if (key.key.keysym.sym == SDLK_RIGHT)
    {
        position.x += speed;
    }
    if (key.key.keysym.sym == SDLK_LEFT)
    {
        position.x -= speed;
    }

    refresh();
}

void Plane::change_weapon(Weapon weapon)
{
}

void Plane::shoot()
{
}

void Plane::refresh()
{
    hitbox->set_x(position.x);
    hitbox->set_y(position.y);

    SDL_RenderCopy(target_renderer, texture, nullptr, &position);
}





