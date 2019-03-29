//
// Created by Avala on 2019/3/26.
//

#ifndef PLANE_BATTLE_MENU_H
#define PLANE_BATTLE_MENU_H

#include "Window.h"

class menu
{
private:
    SDL_Texture *start_buttom = nullptr;
    SDL_Texture *continue_buttom = nullptr;
    SDL_Renderer *target_renderer = nullptr;



public:
    menu(Window &target_window)
    {
        this->target_renderer = target_window.get_renderer();
    }

    void show_menu();
};



#endif //PLANE_BATTLE_MENU_H
