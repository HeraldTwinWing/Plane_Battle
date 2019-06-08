#include "Level.h"


Level::Level(int level, GameData *gameData)
{
    this->startTime = SDL_GetTicks();
    this->lastTime = 0;
    this->thisTime = this->startTime;
    this->deltaTime = 0;
    this->levelNum = level;
    this->gameData = gameData;
}


Level::~Level()
{
}

void Level::spawnEntity(GameData *gameData, const std::string &entityType, int levelnum, int entityNum)
{
    if (entityType == "enemy")
    {
        Save LevelSave;
        LevelSave.getLevelInfo(levelnum, entityNum);
        gameData->enemies.push_back(Enemy{new HitBox(SQUARE_HITBOX, 100), gameData->mainWindow, LevelSave});
        gameData->enemies[entityNum].spawn();

    }
}

void Level::levelexecute()
{
    lastTime = thisTime;
    thisTime = SDL_GetTicks();
    deltaTime = (thisTime - lastTime) / 1000.0;
    if (deltaTime == 0)
    {
        spawnEntity(gameData,"enemy",levelNum,0);
    }
    else if(deltaTime == 2)
    {
        spawnEntity(gameData,"enemy",levelNum,1);
    }
}
