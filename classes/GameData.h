//
// Created by Avalanche_Exia on 2019/4/17.
//

#ifndef PLANE_BATTLE_GAMEDATA_H
#define PLANE_BATTLE_GAMEDATA_H

#include <SDL2/SDL.h>
#include <deque>
#include "Plane.h"
#include "Enemy.h"
#include "Bullet.h"

class GameData
{
public:
	int ScreenWidth;
	int ScreenHeight;
	int ScreenBPP;
	Uint32 ScreenFlags;

	bool running;

	double thisTime;
	double lastTime;
	double deltaTime;

	Window *main_window;
	//¼º·½·É»ú
	Plane *player;

	std::deque<Bullet> player_bullets;
	std::deque<Bullet> enemy_bullets;
	std::deque<Enemy> enemys;

	void addPlayerBullet();
	void addEnemyBullet(Enemy& enemy);
	void addEnemy(Enemy& enemy);
};


#endif //PLANE_BATTLE_GAMEDATA_H
