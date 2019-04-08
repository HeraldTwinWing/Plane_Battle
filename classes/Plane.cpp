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
    SDL_RenderCopy(target_renderer, texture, nullptr, &position);
}

void Plane::move()
{
    if ( moving[0] && position.y >= 0 )
    {
        position.y -= speed;
    }
    if ( moving[1] && position.y <= 520 )
    {
        position.y += speed;
    }
    if ( moving[2] && position.x >= 0 )
    {
        position.x -= speed;
    }
    if ( moving[3] && position.x <= 1080 )
    {
        position.x += speed;
    }

    refresh();
}

void Plane::change_weapon(Weapon weapon)
{
}

void Plane::shoot()
{
    switch (weapon.get_weapon_category())
    {

    }
}

void Plane::refresh()
{
    hitbox->set_x(position.x);
    hitbox->set_y(position.y);

    SDL_RenderCopy(target_renderer, texture, nullptr, &position);
}

void Plane::set_moving(SDL_Event event)
{
    if ( event.type == SDL_KEYDOWN )
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                moving[0] = true;
                moving[1] = false;
                break;
            case SDLK_DOWN:
                moving[1] = true;
                moving[0] = false;
                break;
            case SDLK_LEFT:
                moving[2] = true;
                moving[3] = false;
                break;
            case SDLK_RIGHT:
                moving[3] = true;
                moving[2] = false;
                break;
            default:break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                moving[0] = false;
                break;
            case SDLK_DOWN:
                moving[1] = false;
                break;
            case SDLK_LEFT:
                moving[2] = false;
                break;
            case SDLK_RIGHT:
                moving[3] = false;
                break;
            default:break;
        }
    }
}

void Plane::handle_event(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_SPACE:
            shoot();
    }
}





