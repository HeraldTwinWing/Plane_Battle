//
// Created by Avalanche_Exia on 2019/4/3.
//

#ifndef PLANE_BATTLE_GAME_H
#define PLANE_BATTLE_GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "Window.h"
#include "Plane.h"


class Game
{

public:
    Game();

    ~Game();

    void OnExecute();

    void OnThink();

    void OnUpdate();

    void OnRender();

private:
    int ScreenWidth;
    int ScreenHeight;
    int ScreenBPP;
    Uint32 ScreenFlags;

    bool running;

    double thisTime;
    double lastTime;
    double deltaTime;

    SDL_Window *window;
    SDL_Event event;

    Window *main_window;
    //¼º·½·É»ú
    Plane *my_plane;

//    std::vector<Enemy> enemys;
};


#endif //PLANE_BATTLE_GAME_H
