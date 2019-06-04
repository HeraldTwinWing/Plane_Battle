//
// Created by Avalanche_Exia on 2019/4/3.
//
#pragma once

#include <SDL2/SDL.h>
#include <deque>
#include <memory>
#include "Window.h"
#include "UI.h"
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

    void playerBulletMoveAndHitDeterminate();

    void gamingUpdate();

    SDL_Window *window;
    SDL_Event event;

    GameEvent *eventHandle;
    GameData *gameData;
};

