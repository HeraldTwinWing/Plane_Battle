//
// Created by Avalanche_Exia on 2019/3/17.
//

#ifndef PLANE_BATTLE_SCREEN_H
#define PLANE_BATTLE_SCREEN_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <map>
#include <utility>

class Window
{
private:
    int window_width = 0;
    int window_height = 0;

    //两个Rect用于实现背景循环
    //背景1位置
    SDL_Rect background1_pos;
    //背景2位置
    SDL_Rect background2_pos;

    //指向对应窗口
    SDL_Window *window = nullptr;
    //指向背景图景所在渲染器
    SDL_Renderer *renderer = nullptr;
    //指向背景图片
    SDL_Texture *background = nullptr;

    //储存已加载材质
    std::map<std::string, SDL_Texture *> textures;

    //记录背景移动的时刻
    double background_last_move;

public:
    Window(int width, int height);

    //创建窗口并返回指向它的指针
    //该方法会使window成员指向该窗口
    SDL_Window *create_window(const std::string &title);

    //创建指向该窗口的渲染器
    SDL_Renderer *create_renderer(bool default_renderer=true);

    //加载背景并返回指向图片的指针
    //向textures容器中添加返回的指针
    SDL_Texture *load_picture(const std::string &filename);
    void load_background();


    //显示图片
    void show_background();
    void show_image(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect pos);
    void show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, int y, int x);
    void show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, int y, int w, int h, int x);

    void background_move(double this_time);

    void set_background(SDL_Texture *texture)
    {
        this->background = texture;
    }

    SDL_Window *get_window()
    {
        return window;
    }

    SDL_Renderer *getRenderer()
    {
        return renderer;
    }


    ~Window();
};

SDL_Texture *load_picture(const std::string &filename, SDL_Renderer *target_renderer);


#endif //PLANE_BATTLE_SCREEN_H
