#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "HitBox.h"
#include "Weapon.h"
#include "Window.h"

class Plane
{
private:
    //����ֵ
    int max_health;
    int health;

    //�ƶ��ٶ�
    int speed;
    //�������ҵ��ƶ�״̬
    bool moving[4] = {false, false, false, false};

    //��������
    Weapon* weapon;

    //�����ж���
    HitBox *hitbox;

    //�������С
    SDL_Rect position;

    SDL_Texture *texture = nullptr;

    //�ɻ����ڵ���Ⱦ��[ͼ��]
    Window *window = nullptr;
public:
    Plane(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
          const std::string &texture_name, Window *window);

    Plane(int max_health, int speed, HitBox *hitbox,
          const std::string &texture_name, Window *window);

    Plane(Plane &plane);

    //���ɵ�λ
    void spawn();

    /*���Ʒɴ��ƶ�
     * �÷��������ƶ�����(����)
     * �����ٶȿ��Ʒɴ�������÷���ı�
     * */
    void move();

    //������ɻ���صİ����¼�
    void handle_event(SDL_Event event);

    /*�ܵ��˺�
     * �����˺������۳���Ӧ��������ֵ
     * �۳�������ֵ����0����true�����򷵻�false
     * */
    bool damage(int damage_amount);

    /*�л�����
     * ʰȡ������ı䵱ǰ��������
     * */
    void change_weapon(Weapon weapon);

    /*���
     * �����������ഴ����Ӧ���ӵ�����
     * */
    Bullet shoot();

    //ˢ�¸ö���״̬
    //������ͼλ����hitboxλ��
    void refresh();

    void set_moving(SDL_Event event);
};