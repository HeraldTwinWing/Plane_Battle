#include "Level.h"



Level::Level(int level,GameData *gameData)
{
//    spawnEntity(gameData,"enemy",level,0);
//    gameData->enemies[0].MoveAsLine(-1);
//    spawnEntity(gameData,"enemy",level,1);
//    gameData->enemies[1].move();
//    spawnEntity(gameData,"enemy",level,2);
//    gameData->enemies[2].MoveAsSin();
}


Level::~Level()
{
}

void Level::spawnEntity(GameData *gameData, const std::string &entityType,int levelnum, int entityNum)
{
    if(entityType == "enemy")
    {
        Save LevelOneSave;
        LevelOneSave.getLevelOneInfo(levelnum,entityNum);
        gameData->enemies.push_back(Enemy{new HitBox(SQUARE_HITBOX, 100), gameData->mainWindow, LevelOneSave});
        gameData->enemies[entityNum].spawn();

    }
}
