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
#include "Level.h"
//#include "Save.h"


class Game
{
public:
    Game(GameData *gameData, UI *ui);

    ~Game();

    void OnExecute();

    void OnThink();

    void OnUpdate();

    void OnRender();

    void playerBulletMoveAndHitDeterminate();

	void enemyBulletMoveAndHitDeterminate();

    void gamingUpdate();

    void pauseUpdate();

    void menuUpdate();

    //SDL_Window *window;
    SDL_Event event;

    GameEvent *eventHandle;
    GameData *gameData;
    Level* level;
    UI *ui;
};

