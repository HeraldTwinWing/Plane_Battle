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

    std::unique_ptr<SDL_Window> window;
    SDL_Event event;

    std::unique_ptr<GameEvent> event_handle;
    std::unique_ptr<GameData> game_data;
};

