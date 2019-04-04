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

    main_window = new Window(ScreenWidth, ScreenHeight);
    main_window->create_window("Plane Battle");
    renderers.push_back(main_window->create_renderer());
    main_window->load_background();
    main_window->show_background();

//    SDL_Renderer *my_plane_renderer = main_window->create_renderer(false);
//    renderers.push_back(my_plane_renderer);
    my_plane = new Plane(1000, 10, new HitBox("square"), 200, SDL_WINDOWPOS_CENTERED,
                         "default_ship.png", main_window->get_renderer());
    my_plane->spawn();
}

Game::~Game()
{
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
        if (event.type == SDL_KEYDOWN)
            my_plane->move(event);

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

    SDL_RenderClear(main_window->get_renderer());
    main_window->background_move(thisTime);
    my_plane->refresh();
}

void Game::OnRender()
{
    SDL_RenderPresent(main_window->get_renderer());
}