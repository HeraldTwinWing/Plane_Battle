#include "classes/Window.h"
#include "classes/menu.h"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    Window main_window(1280, 720);
    main_window.create_window("Plane Battle");
    main_window.create_renderer();
    SDL_Texture* back = main_window.load_picture("background.png");
    main_window.show_image(back, 0, 0, 1920, 720);
    SDL_RenderPresent(main_window.get_renderer());
    menu menu1(main_window);
    menu1.show_menu();

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    SDL_Quit();
    return 0;
}