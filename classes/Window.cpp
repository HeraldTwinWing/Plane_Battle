//
// Created by Avalanche_Exia on 2019/3/17.
//

#include "Window.h"


Window::Window(int width, int height)
{
    window_width = width;
    window_height = height;

    background1_pos.x = 0;
    background1_pos.y = 0;
    background1_pos.w = 1920;
    background1_pos.h = 720;
    background2_pos.x = 1280;
    background2_pos.y = 0;
    background2_pos.w = 1920;
    background2_pos.h = 720;
}

SDL_Window *Window::create_window(const std::string &title)
{
    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              window_width, window_height, SDL_WINDOW_SHOWN);
    if ( window == nullptr )
    {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }

    return window;
}

SDL_Renderer *Window::create_renderer(bool default_renderer)
{
    SDL_Renderer *new_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if ( new_renderer == nullptr )
    {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }
    if ( default_renderer )
    {
        this->renderer = new_renderer;
    }

    return new_renderer;
}

SDL_Texture *Window::load_picture(const std::string &filename)
{
    if (textures.find(filename) != textures.end())
    {
        return textures[filename];
    }
    else
    {
        std::string path = "../pictures/" + filename;
        SDL_Surface *loaded_image = nullptr;
        SDL_Texture *texture = nullptr;

        loaded_image = IMG_Load(path.c_str());
        if ( loaded_image == nullptr )
        {
            std::cout << SDL_GetError() << std::endl;
            return nullptr;
        }
        texture = SDL_CreateTextureFromSurface(renderer, loaded_image);
        textures[filename] = texture;

        SDL_FreeSurface(loaded_image);

        return textures[filename];
    }
}

void Window::show_background()
{

    if ( background1_pos.x >= -1920 && background1_pos.x <= 1280 )
    {
        SDL_RenderCopy(renderer, background, nullptr, &background1_pos);
    }
    if ( background2_pos.x >= -1920 && background2_pos.x <= 1280 )
    {
        SDL_RenderCopy(renderer, background, nullptr, &background2_pos);
    }
}

void Window::show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, SDL_Rect pos)
{
    SDL_RenderCopy(target_renderer, texture, nullptr, &pos);
}

void Window::show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, int y, int x)
{
    SDL_Rect position;
    position.x = x;
    position.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);

    SDL_RenderCopy(target_renderer, texture, nullptr, &position);
}

void Window::show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, int y, int w, int h, int x)
{
    SDL_Rect position;
    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;

    SDL_RenderCopy(target_renderer, texture, nullptr, &position);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    for ( std::pair<std::string, SDL_Texture*> p: textures )
    {
        SDL_DestroyTexture(p.second);
    }
    textures.clear();
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::background_move(double this_time)
{
    //左移背景
    if ( this_time - background_last_move > 10 )
    {
        background1_pos.x -= 1;
        background2_pos.x -= 1;
    }

    //当一张背景移出屏幕后将其拼接到另一背景之后
    if ( background1_pos.x < -background1_pos.w )
        background1_pos.x = background2_pos.x + background1_pos.w;
    if ( background2_pos.x < -background2_pos.w )
        background2_pos.x = background1_pos.x + background2_pos.w;
    this->show_background();
}

void Window::load_background()
{
    SDL_Texture *background_image = this->load_picture("background.png");
    this->background = background_image;
}


SDL_Texture *load_picture(const std::string &filename, SDL_Renderer *target_renderer)
{
    std::string path = "../pictures/" + filename;
    SDL_Surface *loaded_image = nullptr;
    SDL_Texture *texture = nullptr;

    loaded_image = IMG_Load(path.c_str());
    if ( loaded_image == nullptr )
    {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }
    texture = SDL_CreateTextureFromSurface(target_renderer, loaded_image);

    SDL_FreeSurface(loaded_image);

    return texture;
}
