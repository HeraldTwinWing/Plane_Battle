#include "Plane.h"



Plane::Plane(int max_health, int speed, HitBox& hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window& target_window)
{
    this->max_health    = max_health;
    this->health        = max_health;
    this->speed         = speed;
    this->hitboxs       = hitbox;
    this->coordinate_x  = coordinate_x;
    this->coordinate_y  = coordinate_y;
    this->texture       = load_picture(texture_name, target_window.get_renderer());
    this->target_window = &target_window;
}

Plane::Plane(int max_health, int speed, HitBox& hitbox,
        const std::string &texture_name, Window& target_window)
{
    this->max_health    = max_health;
    this->health        = max_health;
    this->speed         = speed;
    this->hitboxs       = hitbox;
    this->coordinate_y  = -100;
    this->coordinate_x  = SDL_WINDOWPOS_CENTERED;
    this->texture  = load_picture(texture_name, target_window.get_renderer());
    this->target_window = &target_window;
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
    SDL_Rect pos;
    //SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);
    pos.w = 50;
    pos.h = 50;
    pos.x = coordinate_x;
    pos.y = coordinate_y;

    target_window->show_image(texture, pos);
}

void Plane::move(SDL_Event &key)
{
    if (key.key.keysym.sym == SDLK_UP)
    {
        coordinate_y -= speed;
    }
    if (key.key.keysym.sym == SDLK_DOWN)
    {
        coordinate_y += speed;
    }
    if (key.key.keysym.sym == SDLK_RIGHT)
    {
        coordinate_x += speed;
    }
    if (key.key.keysym.sym == SDLK_LEFT)
    {
        coordinate_x -= speed;
    }

    spawn();
}

void Plane::change_weapon(std::string weapon_category)
{
}

void Plane::shoot()
{
}





