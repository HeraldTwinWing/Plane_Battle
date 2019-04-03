#include "classes/Window.h"
#include "classes/menu.h"
#include "classes/Plane.h"

int main(int argc, char *args[])
{
    if ( SDL_Init(SDL_INIT_EVERYTHING) == -1 )
    {
        std::cout << SDL_GetError() << std::endl;
    }

    Window main_window(1280, 720);
    HitBox h;
    main_window.create_window("Plane Battle");
    main_window.create_renderer();
    SDL_Texture *back = main_window.load_picture("background.png");
    int a = 0;
    int b = 0;
    main_window.show_image(back, a, b, 1920, 720);
    SDL_RenderPresent(main_window.get_renderer());
    menu menu1(main_window);
    menu1.show_menu();
    Plane my_plane(1000, 10, h, 100, 100, "plane.png", main_window);
    my_plane.spawn();
    SDL_RenderPresent(main_window.get_renderer());

    bool quit = false;
    SDL_Event event;
    while ( !quit )
    {


        while ( SDL_PollEvent(&event))
        {
            main_window.show_image(back, a, b, 1920, 720);
            my_plane.spawn();
            if ( event.type == SDL_QUIT )
            {
                quit = true;
            }
            if ( event.type == SDL_KEYDOWN )
            {
                if ( event.key.keysym.sym == SDLK_UP   ||
                     event.key.keysym.sym == SDLK_DOWN ||
                     event.key.keysym.sym == SDLK_LEFT ||
                     event.key.keysym.sym == SDLK_RIGHT )
                {

                    my_plane.move(event);
                }
            }

            SDL_RenderPresent(main_window.get_renderer());
        }
    }

    SDL_Quit();
    return 0;
}