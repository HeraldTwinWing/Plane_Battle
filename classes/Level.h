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
	int count = 0;
    GameData *gameData;
    Level(int level,GameData *gameData);
    void levelExecute();
    void spawnEntity( const std::string &entityType, int levelNum, int entityNum);


    ~Level();
};

