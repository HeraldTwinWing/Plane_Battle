//
// Created by Avalanche_Exia on 2019/4/3.
//
#pragma once

#include <SDL2/SDL.h>
#include <deque>
#include <memory>
#include "Window.h"
#include "GameData.h"
#include "GameEvent.h"


class Game
{

public:
    explicit Game(GameData *game_data);

    ~Game();

    void OnExecute();

    void OnThink();

    void OnUpdate();

    void OnRender();


    SDL_Window *window;
    SDL_Event event;

    GameEvent *event_handle;
    GameData *game_data;
};

