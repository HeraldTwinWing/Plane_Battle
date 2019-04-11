#pragma once

#include <string>
#include "Weapon.h"


class HitBox
{
public:


    //Hitbox ��������
    int center_x;
    int center_y;
    int radius;

    std::string category;

    explicit HitBox(std::string category);

    /*�����ж�
     * ����hitbox��������������Ĳ�ͬ
     * ѡ���Ӧ���ж�����
     * ���з���true,���򷵻�false
     * */
    bool ifBulletHit(Bullet *bullet);

    bool square_hitbox_hit_by_bullet();

    bool square_hitbox_hit_by_beam();

    bool circle_hitbox_hit_by_bullet();

    bool circle_hitbox_hit_by_beam();

    void set_x(int x);
    void set_y(int y);
    ~HitBox();
};