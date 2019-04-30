//
// Created by Avalanche_Exia on 2019/4/3.
//

#include "Game.h"

Game::Game(GameData *game_data)
{
    this->game_data = game_data;
    game_data->ScreenWidth = 1280;
    game_data->ScreenHeight = 720;
    game_data->ScreenBPP = 32;

    game_data->running = true;

    if ( SDL_Init(SDL_INIT_EVERYTHING) == -1 )
    {
        std::cout << SDL_GetError() << std::endl;
    }

    //创建主窗口并加载背景
    game_data->main_window = new Window(game_data->ScreenWidth, game_data->ScreenHeight);
    game_data->main_window->create_window("Plane Battle");
    game_data->main_window->create_renderer();
    game_data->main_window->load_background();
    game_data->main_window->show_background();

    event_handle = new GameEvent(game_data);


    game_data->player = new Plane(1000, 200, new HitBox(SQUARE_HITBOX, 10), 200, 360,
                                  "default_ship.png", game_data->main_window);
    game_data->player->spawn();

    //测试用代码
    game_data->enemys.push_back({1000, 200, new HitBox(SQUARE_HITBOX, 100), 500, 360,
                                 "default_ship.png", game_data->main_window});
    game_data->enemys[0].spawn();
}

Game::~Game()
{
    delete game_data->main_window;
    delete game_data->player;
    SDL_Quit();
}

void Game::OnExecute()
{
    while ( game_data->running )
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
            game_data->running = false;

        event_handle->OnEvent(event);

    }
}

void Game::OnUpdate()
{
    game_data->lastTime = game_data->thisTime;
    game_data->thisTime = SDL_GetTicks();
    game_data->deltaTime = (game_data->thisTime - game_data->lastTime) / 1000.0;

    game_data->addPlayerBullet();

    int hitBullet = -1;
    game_data->player->move();

    for ( auto player_bullet = game_data->player_bullets.begin();
          player_bullet < game_data->player_bullets.end(); ++player_bullet )
    {
        player_bullet->move();
        for ( auto enemy = game_data->enemys.begin(); enemy < game_data->enemys.end(); enemy++ )
        {
            if ( enemy->hitbox->ifBulletHit(&*player_bullet))
            {
                std::cout << "hit" << std::endl;
                if ( enemy->damage(player_bullet->atk))
                {
                    enemy = game_data->enemys.erase(enemy);
                }
                player_bullet = game_data->player_bullets.erase(player_bullet);
            }
        }
    }
    if ( hitBullet >= 0 )
    {
        game_data->player_bullets.erase(game_data->player_bullets.begin() + hitBullet,
                                        game_data->player_bullets.begin() + hitBullet + 1);
        game_data->player_bullets.shrink_to_fit();
    }

    //击中判定测试代码
    //std::cout << "LP: " << game_data->enemys[0].health << std::endl;

    SDL_RenderClear(game_data->main_window->get_renderer());
    game_data->main_window->background_move(game_data->thisTime);

    int last_need_delete_bullet = 0;
    for ( int j = 0; j < game_data->player_bullets.size(); ++j )
    {
        game_data->player_bullets[j].show_image();
        if ( game_data->player_bullets[j].position.x < -30 || game_data->player_bullets[j].position.x > 1300 ||
             game_data->player_bullets[j].position.y < -30 || game_data->player_bullets[j].position.y > 750 )
        {
            last_need_delete_bullet = j;
        }
    }
    game_data->player_bullets.erase(game_data->player_bullets.begin(),
                                    game_data->player_bullets.begin() + last_need_delete_bullet);
    game_data->player_bullets.shrink_to_fit();
    //std::cout << player_bullets.size() << std::endl;

    //刷新玩家飞机状态
    game_data->player->refresh();

    for ( auto &i: game_data->enemys )
    {
        i.refresh();
    }
}

void Game::OnRender()
{
    SDL_RenderPresent(game_data->main_window->get_renderer());
}