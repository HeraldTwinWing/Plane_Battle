//
// Created by Avalanche_Exia on 2019/4/3.
//

#include "Game.h"

Game::Game(GameData* game_data)
{
    this->gameData = game_data;
    game_data->ScreenWidth = 1280;
    game_data->ScreenHeight = 720;
    game_data->ScreenBPP = 32;

    game_data->running = true;

    if ( SDL_Init(SDL_INIT_EVERYTHING) == -1 )
    {
        std::cout << SDL_GetError() << std::endl;
    }

    //创建主窗口并加载背景
    game_data->mainWindow = new Window(game_data->ScreenWidth, game_data->ScreenHeight);
    game_data->mainWindow->create_window("Plane Battle");
    game_data->mainWindow->create_renderer();
    game_data->mainWindow->load_background();
    game_data->mainWindow->show_background();

    event_handle = new GameEvent(game_data);


    game_data->player = new Plane(1000, 400, new HitBox(SQUARE_HITBOX, 10), 200, 360,
                                  "default_ship.png", game_data->mainWindow);
    game_data->player->spawn();

    //测试用代码
    game_data->enemies.push_back({1000, 200, new HitBox(SQUARE_HITBOX, 100), 500, 360,
                                  "default_ship.png", game_data->mainWindow});
    game_data->enemies[0].spawn();
}

Game::~Game()
{
    delete gameData->mainWindow;
    delete gameData->player;
    SDL_Quit();
}

void Game::OnExecute()
{
    while ( gameData->running )
    {
        OnThink();
        OnUpdate();
        OnRender();
    }
}

void Game::OnThink()
{
    double frame_time = SDL_GetTicks();
    while ( SDL_PollEvent(&event))
    {
        if ( event.type == SDL_QUIT )
            gameData->running = false;

        event_handle->OnEvent(event);

    }
}

void Game::OnUpdate()
{
    gameData->lastTime = gameData->thisTime;
    gameData->thisTime = SDL_GetTicks();
    gameData->deltaTime = (gameData->thisTime - gameData->lastTime) / 1000.0;
    SDL_RenderClear(gameData->mainWindow->getRenderer());
    gameData->mainWindow->background_move(gameData->thisTime);

    //玩家相关状态更新
    gameData->addPlayerBullet();
    gameData->player->move();
    playerBulletMoveAndHitDeterminate();
    gameData->player->refresh();


    //std::cout << playerBullets.size() << std::endl;


    for ( auto& i: gameData->enemies )
    {
        i.refresh();
    }
}

void Game::OnRender()
{
    SDL_RenderPresent(gameData->mainWindow->getRenderer());
}

void Game::playerBulletMoveAndHitDeterminate()
{
    int lastNeedDeleteBullet = 0;
    for ( int j = 0; j < gameData->playerBullets.size(); ++j )
    {
        gameData->playerBullets[j].show_image();
        if ( gameData->playerBullets[j].position.x < -30 || gameData->playerBullets[j].position.x > 1300 ||
             gameData->playerBullets[j].position.y < -30 || gameData->playerBullets[j].position.y > 750 )
        {
            lastNeedDeleteBullet = j;
        }
    }
    gameData->playerBullets.erase(gameData->playerBullets.begin(),
                                  gameData->playerBullets.begin() + lastNeedDeleteBullet);

    for ( auto playerBullet = gameData->playerBullets.begin();
          playerBullet < gameData->playerBullets.end(); ++playerBullet )
    {
        playerBullet->move();
        for ( auto enemy = gameData->enemies.begin(); enemy < gameData->enemies.end(); enemy++ )
        {
            if ( enemy->hitbox->ifBulletHit(&*playerBullet))
            {
                std::cout << "hit" << std::endl;
                if ( enemy->damage(playerBullet->atk))
                {
                    enemy = gameData->enemies.erase(enemy);
                }
                playerBullet = gameData->playerBullets.erase(playerBullet);
            }
        }
    }
    gameData->playerBullets.shrink_to_fit();
}
