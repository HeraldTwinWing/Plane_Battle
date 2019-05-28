#pragma once

#include <string>
#include "Weapon.h"

enum hitbox_category{SQUARE_HITBOX, CIRCLE_HITBOX};

class HitBox
{
public:

    //Hitbox 中心坐标
    int center_x;
    int center_y;

    hitbox_category category;
    int size[2];
    int radius;

    HitBox(hitbox_category category, int radius);

    /*击中判定
     * 根据hitbox种类与武器种类的不同
     * 选择对应的判定方法
     * 击中返回true,否则返回false
     * */
    bool hit(WeaponCategoryEnum weapon_category, Bullet *bullet = nullptr);

	bool ifBulletHit(Bullet *bullet);

	bool ifBeamHit();

    void set_x(int x);
    void set_y(int y);
    ~HitBox();


};