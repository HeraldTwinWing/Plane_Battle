//
// Created by Avala on 2019/3/26.
//

#include "menu.h"

void menu::show_menu()
{
    SDL_Texture *start_button = load_picture("start_button.png", target_renderer);

    SDL_Rect position;
    position.x = 0;
    position.y = 0;

    SDL_QueryTexture(start_button, nullptr, nullptr, &position.w, &position.h);
    SDL_RenderCopy(target_renderer, start_button, nullptr, &position);
    SDL_RenderPresent(target_renderer);
}