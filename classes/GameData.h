//
// Created by Avalanche_Exia on 2019/4/17.
//

#ifndef PLANE_BATTLE_GAMEDATA_H
#define PLANE_BATTLE_GAMEDATA_H

#include <SDL2/SDL.h>
#include <deque>
#include "Enemy.h"
#include "Bullet.h"

enum GameStatus{MAIN_MENU, GAMING, PAUSE};

class GameData
{
public:
	int ScreenWidth;
	int ScreenHeight;
	int ScreenBPP;
	Uint32 ScreenFlags;

	GameStatus gameStatus;
	bool running = false;
	bool pause = false;

	double thisTime = 0;
	double lastTime = 0;
	double deltaTime = 0;

	Window *mainWindow;
	//己方飞机
	Plane *player;

	std::deque<Bullet> playerBullets;
	std::deque<Bullet> enemyBullets;
	std::deque<Enemy> enemies;

	//判断是否开火并添加子弹到容器
	void addPlayerBullet();
	void addEnemyBullet(Enemy& enemy);
	void addEnemy(Enemy& enemy);

	GameData()=default;
	~GameData();
};


#endif //PLANE_BATTLE_GAMEDATA_H
