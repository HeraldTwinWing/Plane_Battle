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

    //�������ڲ�����ָ������ָ��
    //�÷�����ʹwindow��Աָ��ô���
    SDL_Window *create_window(const std::string &title);

    //����ָ��ô��ڵ���Ⱦ��
    SDL_Renderer *create_renderer();

    //���ر���������ָ��ͼƬ��ָ��
    //��textures��������ӷ��ص�ָ��
    SDL_Texture *load_picture(const std::string &filename);


    //��ʾͼƬ
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
