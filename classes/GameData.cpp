//
// Created by Avalanche_Exia on 2019/4/17.
//

#include "GameData.h"


void GameData::addPlayerBullet()
{
    if ( player->if_firing() && player->if_not_in_fire_CD())
        player->fire(playerBullets);
}

void GameData::addEnemyBullet(Enemy& enemy)
{
    enemy.fire(enemyBullets);
}

void GameData::addEnemy(Enemy& enemy)
{
    enemies.push_back(enemy);
}

GameData::~GameData()
{
	delete mainWindow;
	delete player;
	enemies.clear();
	playerBullets.clear();
	enemyBullets.clear();
}

