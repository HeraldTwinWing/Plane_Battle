//
// Created by Avalanche_Exia on 2019/4/17.
//

#include "GameData.h"


void GameData::addPlayerBullet()
{
    if (player->if_firing() && player->if_not_in_fire_CD())
	    player_bullets.push_back(player->fire());
}

void GameData::addEnemyBullet(Enemy& enemy)
{
	enemy_bullets.push_back(enemy.fire());
}

void GameData::addEnemy(Enemy &enemy)
{
	enemys.push_back(enemy);
}

