#pragma once

#include <string>
#include "Weapon.h"

enum hitbox_category{SQUARE_HITBOX, CIRCLE_HITBOX};

class HitBox
{
public:

    //Hitbox ��������
    int center_x;
    int center_y;

    hitbox_category category;
    int size[2];
    int radius;

    HitBox(hitbox_category category, int radius);

    /*�����ж�
     * ����hitbox��������������Ĳ�ͬ
     * ѡ���Ӧ���ж�����
     * ���з���true,���򷵻�false
     * */
    bool hit(WeaponCategoryEnum weapon_category, Bullet *bullet = nullptr);

	bool ifBulletHit(Bullet *bullet);

	bool ifBeamHit();

    void set_x(int x);
    void set_y(int y);
    ~HitBox();


};