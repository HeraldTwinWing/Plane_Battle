//
// Created by Avalanche_Exia on 2019/3/17.
//

#ifndef PLANE_BATTLE_SCREEN_H
#define PLANE_BATTLE_SCREEN_H

#include "string"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "iostream"
#include "vector"

class Window
{
private:
    int window_width = 0;
    int window_height = 0;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    std::vector<SDL_Texture *> textures;

public:
    Window(int width, int height);

    //创建窗口并返回指向它的指针
    //该方法会使window成员指向该窗口
    SDL_Window *create_window(const std::string &title);

    //创建指向该窗口的渲染器
    SDL_Renderer *create_renderer();

    //加载背景并返回指向图片的指针
    //向textures容器中添加返回的指针
    SDL_Texture *load_picture(const std::string &filename);


    //显示图片
    void show_image(SDL_Texture *texture, int x, int y);
    void show_image(SDL_Texture *texture, int x, int y, int w, int h);

    SDL_Window *get_window()
    {
        return window;
    }

    SDL_Renderer *get_renderer()
    {
        return renderer;
    }

    SDL_Texture *get_texture(int index)
    {
        return textures[index];
    }

    ~Window();
};

SDL_Texture *load_picture(const std::string &filename, SDL_Renderer *target_renderer);


#endif //PLANE_BATTLE_SCREEN_H
