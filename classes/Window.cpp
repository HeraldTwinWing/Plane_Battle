//
// Created by Avalanche_Exia on 2019/3/17.
//

#include "Window.h"


Window::Window(int width, int height)
{
    window_width = width;
    window_height = height;
}

SDL_Window *Window::create_window(const std::string &title)
{
    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              window_width, window_height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }

    return window;
}

SDL_Renderer *Window::create_renderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }

    return renderer;
}

SDL_Texture *Window::load_picture(const std::string &filename)
{
    std::string path = "../pictures/" + filename;
    SDL_Surface *loaded_image = nullptr;
    SDL_Texture *texture = nullptr;

    loaded_image = IMG_Load(path.c_str());
    if (loaded_image == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }
    texture = SDL_CreateTextureFromSurface(renderer, loaded_image);
    textures.push_back(texture);

    SDL_FreeSurface(loaded_image);

    return texture;
}

void Window::show_image(SDL_Texture *texture, int x, int y)
{
    SDL_Rect position;
    position.x = x;
    position.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);

    SDL_RenderCopy(renderer, texture, nullptr, &position);
}

void Window::show_image(SDL_Texture *texture, int x, int y, int w, int h)
{
    SDL_Rect position;
    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;

    SDL_RenderCopy(renderer, texture, nullptr, &position);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    for (SDL_Texture *texture: textures)
    {
        SDL_DestroyTexture(texture);
    }
    SDL_DestroyWindow(window);
}








