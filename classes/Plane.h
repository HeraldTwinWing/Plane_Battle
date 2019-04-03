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

    //��������
    Weapon weapon;

    //�����ж���
    HitBox hitboxs;

    //����
    int coordinate_x;
    int coordinate_y;

    SDL_Texture *texture = nullptr;

    Window *target_window = nullptr;
public:
    Plane(int max_health, int speed, HitBox &hitbox, int coordinate_x, int coordinate_y,
          const std::string &texture_name, Window &target_window);

    Plane(int max_health, int speed, HitBox &hitbox,
          const std::string &texture_name, Window &target_window);

    Plane(Plane &plane);

    //���ɵ�λ
    void spawn();

    /*���Ʒɴ��ƶ�
     * �÷��������ƶ�����(����)
     * �����ٶȿ��Ʒɴ�������÷���ı�
     * */
    void move(SDL_Event &key);

    /*�ܵ��˺�
     * �����˺������۳���Ӧ��������ֵ
     * �۳�������ֵ����0����true�����򷵻�false
     * */
    bool damage(int damage_amount);

    /*�л�����
     * ʰȡ������ı䵱ǰ��������
     * */
    void change_weapon(std::string weapon_category);

    /*���
     * �����������ഴ����Ӧ���ӵ�����
     * */
    void shoot();


};