#pragma once

#include <utility>
#include <queue>
#include "GameData.h"

class Level
{
public:
    double startTime;
    double lastTime;
    double thisTime;
    double deltaTime;
    int levelNum;
    GameData *gameData;
    Level(int level,GameData *gameData);
    void levelexecute();
    void spawnEntity(GameData *gameData, const std::string &entityType, int levelnum, int entityNum);


    ~Level();
};

