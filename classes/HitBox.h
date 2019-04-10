#pragma once

#include <string>
#include "Weapon.h"

class HitBox
{
public:
    //hitbox����[square/circle]
    enum category_list
    {
        square, circle
    };

    //Hitbox ��������
    int center_x;
    int center_y;

    category_list category;

    explicit HitBox(weapon_category_list category);

    /*�����ж�
     * ����hitbox��������������Ĳ�ͬ
     * ѡ���Ӧ���ж�����
     * ���з���true,���򷵻�false
     * */
    bool hit(std::string weapon_category);

    bool square_hitbox_hit_by_bullet();

    bool square_hitbox_hit_by_beam();

    bool circle_hitbox_hit_by_bullet();

    bool circle_hitbox_hit_by_beam();

    void set_x(int x);
    void set_y(int y);
    ~HitBox();
};