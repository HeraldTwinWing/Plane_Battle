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

void Level::spawnEntity(const std::string &entityType, int levelNum, int entityNum)
{
	if (entityType == "enemy")
	{
		Save levelSave;
		levelSave.getLevelInfo(levelNum, entityNum);
		if ((SDL_GetTicks() - gameData->startTime) / 1000 >= levelSave.spawnTime)
			gameData->enemies.push_back({new HitBox(SQUARE_HITBOX, 100), gameData->mainWindow, levelSave});
		//gameData->enemies[entityNum].spawn();
	}
}

void Level::levelExecute()
{
	lastTime = thisTime;
	thisTime = SDL_GetTicks();
	double deltaGaminTime = (thisTime - gameData->startTime) / 1000.0;


	switch (count)
	{
		case 0:
			if (deltaGaminTime >= 0)
			{
				spawnEntity("enemy", levelNum, count);
				++count;
			}
			break;
		case 1:
			if (deltaGaminTime >= 2)
			{
				spawnEntity("enemy", levelNum, count);
				++count;
			}
			break;
		default:
			break;
	}

//	if (deltaGaminTime >= 0)
//	{
//		spawnEntity("enemy", levelNum, 0);
//	}
//	else if (deltaGaminTime >= 2)
//	{
//		spawnEntity("enemy", levelNum, 1);
//	}
}
