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

    //����Rect����ʵ�ֱ���ѭ��
    //����1λ��
    SDL_Rect background1Pos;
    //����2λ��
    SDL_Rect background2Pos;
    SDL_Rect landingPlatformPos;

    //ָ���Ӧ����
    SDL_Window *window = nullptr;
    //ָ�򱳾�ͼ��������Ⱦ��
    SDL_Renderer *renderer = nullptr;
    //ָ�򱳾�ͼƬ
    SDL_Texture *background = nullptr;
    SDL_Texture *landingPlatform = nullptr;

    //�����Ѽ��ز���
    std::map<std::string, SDL_Texture *> textures;

    //��¼�����ƶ���ʱ��
    double background_last_move;

public:
    Window(int width, int height);

    //�������ڲ�����ָ������ָ��
    //�÷�����ʹwindow��Աָ��ô���
    SDL_Window *createWindow(const std::string &title);

    //����ָ��ô��ڵ���Ⱦ��
    SDL_Renderer *createRenderer(bool default_renderer = true);

    //���ر���������ָ��ͼƬ��ָ��
    //��textures��������ӷ��ص�ָ��
    SDL_Texture *loadPicture(const std::string &filename);
    void loadBackground();


    //��ʾͼƬ
    void showBackground();
    void show_image(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect pos);
    void show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, int y, int x);
    void show_image(SDL_Texture *texture, SDL_Renderer *target_renderer, int y, int w, int h, int x);

    void backgroundMove(double this_time, int gameStatus);
    void landingPlatformMove(int gameStatus);

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
