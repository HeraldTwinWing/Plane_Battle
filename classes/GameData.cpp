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

GameData::GameData()
{
	this->ScreenWidth = 1280;
	this->ScreenHeight = 720;
	this->ScreenBPP = 32;

	this->running = true;
	this->gameStatus = MAIN_MENU;

	//创建主窗口并加载背景
	this->mainWindow = new Window(this->ScreenWidth, this->ScreenHeight);
	this->mainWindow->createWindow("Plane Battle");
	this->mainWindow->createRenderer();
	this->mainWindow->loadBackground();
	this->mainWindow->showBackground();
}
