//
// Created by Avalanche_Exia on 2019/4/3.
//
#pragma once

#include <SDL2/SDL.h>
#include <deque>
#include "Window.h"
#include "Plane.h"
#include "GameEvent.h"


class Game
{

public:
    Game();

    ~Game();

    void OnExecute();

    void OnThink();

    void OnUpdate();

    void OnRender();

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

    GameEvent *event_handle;
    Window *main_window;
    //¼º·½·É»ú
    Plane *player;

    std::deque<Bullet> player_bullets;
    std::deque<Bullet> enemy_bullets;
//    std::vector<Enemy> enemys;
};

