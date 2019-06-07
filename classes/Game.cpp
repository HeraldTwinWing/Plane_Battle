//
// Created by Avalanche_Exia on 2019/4/3.
//

#include "Game.h"

Game::Game(GameData *gameData, UI *ui)
{
	this->gameData = gameData;
	this->ui = ui;
	eventHandle = new GameEvent(gameData, ui);

	Save planeSave;
	planeSave.getPlaneInfo();

	gameData->player = new Plane(new HitBox(SQUARE_HITBOX,10),gameData->mainWindow,planeSave);

	//gameData->player = new Plane(1000, 400, new HitBox(SQUARE_HITBOX, 10), 0, 270, "default_ship.png", gameData->mainWindow);

	gameData->player->spawn();

	//测试用代码
	Save enemySave;
	enemySave.getEnemyInfo();
	gameData->enemies.push_back({new HitBox(SQUARE_HITBOX,100),gameData->mainWindow,enemySave});
	//gameData->enemies.push_back({30, 200, new HitBox(SQUARE_HITBOX, 100), 700, 360,
	                            "default_ship.png", gameData->mainWindow});
	gameData->enemies[0].spawn();
}

Game::~Game() = default;

void Game::OnExecute()
{
	while (gameData->running)
	{
		OnThink();
		OnUpdate();
		OnRender();
	}
	//std::cout << "end" << std::endl;
}

void Game::OnThink()
{
	double frame_time = SDL_GetTicks();
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			gameData->running = false;

		eventHandle->OnEvent(event);
	}
}

void Game::OnUpdate()
{
	gameData->lastTime = gameData->thisTime;
	gameData->thisTime = SDL_GetTicks();
	gameData->deltaTime = (gameData->thisTime - gameData->lastTime) / 1000.0;
	SDL_RenderClear(gameData->mainWindow->getRenderer());
	gameData->mainWindow->backgroundMove(gameData->thisTime, gameData->gameStatus);

	if (gameData->gameStatus == GAMING)
		gamingUpdate();
	else if (gameData->gameStatus == MAIN_MENU)
		gameData->player->showImage();

	menuUpdate();
}

void Game::OnRender()
{
	SDL_RenderPresent(gameData->mainWindow->getRenderer());
}

void Game::playerBulletMoveAndHitDeterminate()
{
	int lastNeedDeleteBullet = 0;
	for (int j = 0; j < gameData->playerBullets.size(); ++j)
	{
		gameData->playerBullets[j].show_image();
		if (gameData->playerBullets[j].position.x < -30 || gameData->playerBullets[j].position.x > 1300 ||
		    gameData->playerBullets[j].position.y < -30 || gameData->playerBullets[j].position.y > 750)
		{
			lastNeedDeleteBullet = j;
		}
	}
	gameData->playerBullets.erase(gameData->playerBullets.begin(),
	                              gameData->playerBullets.begin() + lastNeedDeleteBullet);

	for (auto playerBullet = gameData->playerBullets.begin();
	     playerBullet < gameData->playerBullets.end(); ++playerBullet)
	{
		playerBullet->move();
		for (auto enemy = gameData->enemies.begin(); enemy < gameData->enemies.end(); enemy++)
		{
			//测试用代码
			bool hit = false;
			SDL_Point a = {(*playerBullet).position.x, (*playerBullet).position.y};
			if (SDL_PointInRect(&a, &(*enemy).position))
			{
				hit = true;
			}

			if (enemy->hitbox->ifBulletHit(&*playerBullet))
			{
				std::cout << "hit" << std::endl;
				if (enemy->damage(playerBullet->atk))
				{
					enemy = gameData->enemies.erase(enemy);
				}
				playerBullet = gameData->playerBullets.erase(playerBullet);
			}
		}
	}
	gameData->playerBullets.shrink_to_fit();
}

void Game::gamingUpdate()
{
	//玩家相关状态更新
	gameData->addPlayerBullet();    //玩家射击
	gameData->player->move();
	playerBulletMoveAndHitDeterminate();
	gameData->player->refresh();


	//std::cout << playerBullets.size() << std::endl;
	for (auto &i: gameData->enemies)
	{
		i.refresh();
	}
}

void Game::menuUpdate()
{
	this->ui->showButton(gameData->mainWindow, gameData);
}
