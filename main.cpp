#include <iostream>
#include "classes/Window.h"
#include "SDL2/SDL.h"

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
    main_window.show_image(back, 0, 0);
    SDL_RenderPresent(main_window.get_renderer());

    SDL_Delay(2000);

    SDL_Quit();
    return 0;
}