//
// Created by Avalanche_Exia on 2019/4/3.
//

#include "Game.h"

Game::Game()
{
	ScreenWidth = 1280;
	ScreenHeight = 720;
	ScreenBPP = 32;

	running = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << SDL_GetError() << std::endl;
	}


	//创建主窗口并加载背景
	main_window = new Window(ScreenWidth, ScreenHeight);
	main_window->create_window("Plane Battle");
	main_window->create_renderer();
	main_window->load_background();
	main_window->show_background();

	event_handle = new GameEvent();
	event_handle->game = this;

//    SDL_Renderer *my_plane_renderer = main_window->create_renderer(false);
//    renderers.push_back(my_plane_renderer);
	player = new Plane(1000, 1, new HitBox("square"), 200, 360,
	                   "default_ship.png", main_window);
	player->game = this;
	player->spawn();

	enemys.push_back(new Enemy(1000, 1, new HitBox("square"), 700, 360,
                           "default_ship.png", main_window));
	enemys[0]->game = this;
	enemys[0]->spawn();
}

Game::~Game()
{
	delete main_window;
	delete player;
	SDL_Quit();
}

void Game::OnExecute()
{
	while (running)
	{
		OnThink();
		OnUpdate();
		OnRender();
	}
}

void Game::OnThink()
{
	double frame_time = SDL_GetTicks();
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			running = false;

		event_handle->OnEvent(event);

		if (SDL_GetTicks() - frame_time > 0.016)
		{
			break;
		}
	}
}

void Game::OnUpdate()
{
	lastTime = thisTime;
	thisTime = SDL_GetTicks();
	deltaTime = (thisTime - lastTime) / 1000.0;

	player->move();
	for (auto &i : player_bullets)
	{
		i.move();
        for (auto &j: enemys)
        {
            if (j->hitbox->ifBulletHit(&i))
            {
                j->damage(i.atk);
            }
        }
	}

	std::cout << "LP: " <<enemys[0]->health << std::endl;
	enemys[0]->move();

	SDL_RenderClear(main_window->get_renderer());
	main_window->background_move(thisTime);

	int last_need_delete_bullet = 0;
	for ( int j = 0; j < player_bullets.size(); ++j )
	{
		player_bullets[j].show_image();
		if (player_bullets[j].position.x < -30 || player_bullets[j].position.x > 1300 ||
				player_bullets[j].position.y < -30 || player_bullets[j].position.y > 750)
		{
			last_need_delete_bullet = j;
		}
	}
	player_bullets.erase(player_bullets.begin(), player_bullets.begin()+last_need_delete_bullet);
	player_bullets.shrink_to_fit();
	//std::cout << player_bullets.size() << std::endl;

	player->refresh();
}

void Game::OnRender()
{
	SDL_RenderPresent(main_window->get_renderer());
}